CXX = g++
CXXFLAGS = -std=c++11

all: Sender Receiver

Sender: Sender.o PosixMsgQueue.o
	$(CXX) $(CXXFLAGS) -o Sender Sender.o PosixMsgQueue.o

Receiver: Receiver.o PosixMsgQueue.o
	$(CXX) $(CXXFLAGS) -o Receiver Receiver.o PosixMsgQueue.o

Sender.o: Sender.cpp PosixMsgQueue.h
	$(CXX) $(CXXFLAGS) -c Sender.cpp

Receiver.o: Receiver.cpp PosixMsgQueue.h
	$(CXX) $(CXXFLAGS) -c Receiver.cpp

PosixMsgQueue.o: PosixMsgQueue.cpp PosixMsgQueue.h
	$(CXX) $(CXXFLAGS) -c PosixMsgQueue.cpp
clean:
	rm -f Sender Receiver Sender.o Receiver.o PosixMsgQueue.o
