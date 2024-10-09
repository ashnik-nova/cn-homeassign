#ifndef __OSPFSIMULATION_OSPFNODE_H_
#define __OSPFSIMULATION_OSPFNODE_H_

#include <omnetpp.h>
#include "OspfMessage_m.h"
#include <map>
#include <vector>
#include <queue>
#include <limits>

using namespace omnetpp;

namespace ospfsimulation {

struct LSA {
    int originId;
    int sequenceNumber;
    std::map<int, int> links;
};

struct RoutingTableEntry {
    int destination;
    int nextHop;
    int cost;
};

class OspfNode : public cSimpleModule
{
  private:
    int nodeId;
    std::map<int, int> neighbors;  // neighbor -> port
    std::map<int, LSA> lsdb;  // Link State Database
    std::vector<RoutingTableEntry> routingTable;

    void sendHello();
    void processHello(HelloPacket *msg);
    void floodLSA();
    void processLSA(LsaPacket *msg);
    void runDijkstra();
    void updateRoutingTable(const std::vector<int>& predecessors, const std::vector<int>& distances);

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

}  // namespace ospfsimulation

#endif
