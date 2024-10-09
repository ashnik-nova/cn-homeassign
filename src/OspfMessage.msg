cplusplus {{
#include <vector>
#include <map>
}}

packet OspfPacket {
    int type;  // 1: Hello, 2: LSA
    int sourceId;
}

packet HelloPacket extends OspfPacket {
    int neighborList[];  // Use int array to represent neighbor list
}

packet LsaPacket extends OspfPacket {
    int originId;
    int sequenceNumber;
    int linksKeys[];   // Changed from intVector to int[]
    int linksValues[]; // Changed from intVector to int[]
}
