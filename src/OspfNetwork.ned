package ospfsimulation;

import ned.IdealChannel;

simple OspfNode
{
    parameters:
        int nodeId;
        string connectionsTo;
    gates:
        inout port[];
}

network OspfNetwork
{
    submodules:
        node[8]: OspfNode;
    connections allowunconnected:
        for i=0..7, for j=0..7 {
            node[i].port++ <--> IdealChannel <--> node[j].port++ if i!=j;
        }
}