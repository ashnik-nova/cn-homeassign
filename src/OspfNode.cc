#include "OspfNode.h"
#include <algorithm>

namespace ospfsimulation {

Define_Module(OspfNode);

void OspfNode::initialize()
{
    nodeId = par("nodeId");
    std::string connectionsStr = par("connectionsTo").stdstringValue();
    cStringTokenizer tokenizer(connectionsStr.c_str());
    int port = 0;
    while (tokenizer.hasMoreTokens()) {
        int neighborId = atoi(tokenizer.nextToken());
        neighbors[neighborId] = port++;
    }

    // Initialize own LSA
    LSA ownLSA;
    ownLSA.originId = nodeId;
    ownLSA.sequenceNumber = 0;
    for (const auto& neighbor : neighbors) {
        ownLSA.links[neighbor.first] = 1;  // Assume cost of 1 for all links
    }
    lsdb[nodeId] = ownLSA;

    scheduleAt(simTime() + exponential(1.0), new cMessage("sendHello"));
    scheduleAt(simTime() + exponential(5.0), new cMessage("floodLSA"));
}

void OspfNode::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        if (strcmp(msg->getName(), "sendHello") == 0) {
            sendHello();
            scheduleAt(simTime() + exponential(1.0), msg);
        } else if (strcmp(msg->getName(), "floodLSA") == 0) {
            floodLSA();
            scheduleAt(simTime() + exponential(5.0), msg);
        }
    } else {
        OspfPacket *ospfMsg = check_and_cast<OspfPacket *>(msg);
        if (ospfMsg->getType() == 1) {  // Hello
            processHello(check_and_cast<HelloPacket *>(ospfMsg));
        } else if (ospfMsg->getType() == 2) {  // LSA
            processLSA(check_and_cast<LsaPacket *>(ospfMsg));
        }
        delete msg;
    }
}

void OspfNode::sendHello()
{
    HelloPacket *hello = new HelloPacket("Hello");
    hello->setType(1);
    hello->setSourceId(nodeId);

    // Fix: Set size of NeighborList array and then set elements one by one
    hello->setNeighborListArraySize(neighbors.size());
    int i = 0;
    for (auto& neighbor : neighbors) {
        hello->setNeighborList(i++, neighbor.first);
    }

    for (const auto& neighbor : neighbors) {
        send(hello->dup(), "port$o", neighbor.second);
    }
    delete hello;
}

void OspfNode::processHello(HelloPacket *msg)
{
    EV << "Node " << nodeId << " received Hello from Node " << msg->getSourceId() << endl;
    // Update neighbors if necessary
    if (neighbors.find(msg->getSourceId()) == neighbors.end()) {
        neighbors[msg->getSourceId()] = msg->getArrivalGate()->getIndex();
        // Update own LSA
        lsdb[nodeId].links[msg->getSourceId()] = 1;
        lsdb[nodeId].sequenceNumber++;
        // Trigger LSA flood
        floodLSA();
    }
}

void OspfNode::floodLSA()
{
    LsaPacket *lsaMsg = new LsaPacket("LSA");
    lsaMsg->setType(2);
    lsaMsg->setSourceId(nodeId);
    lsaMsg->setOriginId(nodeId);
    lsaMsg->setSequenceNumber(lsdb[nodeId].sequenceNumber);

    // Fix: Set size of linksKeys array and then set elements one by one
    lsaMsg->setLinksKeysArraySize(lsdb[nodeId].links.size());
    int i = 0;
    for (const auto& link : lsdb[nodeId].links) {
        lsaMsg->setLinksKeys(i, link.first);  // Assuming link.first is the key (neighbor ID)
        lsaMsg->setLinksValues(i++, link.second);  // Assuming link.second is the cost
    }

    for (const auto& neighbor : neighbors) {
        send(lsaMsg->dup(), "port$o", neighbor.second);
    }
    delete lsaMsg;
}

void OspfNode::processLSA(LsaPacket *msg)
{
    int originId = msg->getOriginId();
    int sequenceNumber = msg->getSequenceNumber();

    if (lsdb.find(originId) == lsdb.end() || sequenceNumber > lsdb[originId].sequenceNumber) {
        LSA newLSA;
        newLSA.originId = originId;
        newLSA.sequenceNumber = sequenceNumber;

        // Fix: Set links by extracting them from the array in the message
        newLSA.links.clear();
        for (int i = 0; i < (int)msg->getLinksKeysArraySize(); ++i) {
            newLSA.links[msg->getLinksKeys(i)] = msg->getLinksValues(i);  // Assuming the mapping is correct
        }

        lsdb[originId] = newLSA;

        // Flood to other neighbors
        for (const auto& neighbor : neighbors) {
            if (neighbor.first != msg->getSourceId()) {
                LsaPacket *fwdMsg = msg->dup();
                fwdMsg->setSourceId(nodeId);
                send(fwdMsg, "port$o", neighbor.second);
            }
        }

        // Run Dijkstra's algorithm to update routing table
        runDijkstra();
    }
}


void OspfNode::runDijkstra()
{
    std::vector<int> distances(lsdb.size(), std::numeric_limits<int>::max());
    std::vector<int> predecessors(lsdb.size(), -1);
    std::vector<bool> visited(lsdb.size(), false);

    // Create a mapping of nodeId to index
    std::map<int, int> nodeToIndex;
    int index = 0;
    for (const auto& entry : lsdb) {
        nodeToIndex[entry.first] = index++;
    }

    // Start with the current node
    int startIndex = nodeToIndex[nodeId];
    distances[startIndex] = 0;

    for (size_t i = 0; i < lsdb.size(); i++) {
        // Find the minimum distance vertex
        int u = -1;
        int minDist = std::numeric_limits<int>::max();
        for (size_t j = 0; j < lsdb.size(); j++) {
            if (!visited[j] && distances[j] < minDist) {
                u = j;
                minDist = distances[j];
            }
        }

        if (u == -1) break;  // All remaining vertices are inaccessible

        visited[u] = true;

        // Update distances to neighbors
        int currentNodeId = -1;
        for (const auto& entry : nodeToIndex) {
            if (entry.second == u) {
                currentNodeId = entry.first;
                break;
            }
        }

        for (const auto& neighbor : lsdb[currentNodeId].links) {
            int v = nodeToIndex[neighbor.first];
            int weight = neighbor.second;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
            }
        }
    }

    updateRoutingTable(predecessors, distances);
}

void OspfNode::updateRoutingTable(const std::vector<int>& predecessors, const std::vector<int>& distances)
{
    routingTable.clear();

    std::map<int, int> indexToNode;
    for (const auto& entry : lsdb) {
        indexToNode[entry.second.originId] = entry.first;
    }

    for (int i = 0; i < (int)distances.size(); i++) {
        if (i != static_cast<int>(nodeId) && distances[i] < std::numeric_limits<int>::max()) {
            RoutingTableEntry entry;
            entry.destination = indexToNode[i];
            entry.cost = distances[i];

            // Trace back to find the next hop
            int current = i;
            while (predecessors[current] != nodeId) {
                if (predecessors[current] == -1) {
                    // No path exists
                    break;
                }
                current = predecessors[current];
            }
            entry.nextHop = indexToNode[current];

            routingTable.push_back(entry);
        }
    }

    // Print the routing table
    EV << "Node " << nodeId << " Routing Table:" << endl;
    for (const auto& entry : routingTable) {
        EV << "Destination: " << entry.destination << ", Next Hop: " << entry.nextHop << ", Cost: " << entry.cost << endl;
    }
}

}  // namespace ospfsimulation
