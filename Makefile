CXX = g++
CXXFLAGS = -Wall -std=c++14 -I B:/Omnet++/omnetpp-6.0.3/include
LDFLAGS = -L B:/Omnet++/omnetpp-6.0.3/lib -lomnetpp

TARGET = ospf_sim

OBJS = src/OspfNode.o src/OspfMessage_m.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(TARGET)

src/OspfNode.o: src/OspfNode.cc src/OspfNode.h src/OspfMessage_m.h
	$(CXX) -c $(CXXFLAGS) src/OspfNode.cc -o src/OspfNode.o

src/OspfMessage_m.o: src/OspfMessage_m.cc src/OspfMessage_m.h
	$(CXX) -c $(CXXFLAGS) src/OspfMessage_m.cc -o src/OspfMessage_m.o

src/OspfMessage_m.cc src/OspfMessage_m.h: src/OspfMessage.msg
	opp_msgc src/OspfMessage.msg

clean:
	rm -f $(OBJS) $(TARGET) src/OspfMessage_m.cc src/OspfMessage_m.h
