CXX = g++
CXXFLAGS = -std=c++11

all: sender receiver

sender: sender.o NamedPipeSender.o
	$(CXX) $(CXXFLAGS) -o sender sender.o NamedPipeSender.o

receiver: receiver.o NamedPipeReceiver.o
	$(CXX) $(CXXFLAGS) -o receiver receiver.o NamedPipeReceiver.o

sender.o: sender.cpp NamedPipeSender.h
	$(CXX) $(CXXFLAGS) -c sender.cpp

receiver.o: receiver.cpp NamedPipeReceiver.h
	$(CXX) $(CXXFLAGS) -c receiver.cpp

NamedPipeSender.o: NamedPipeSender.cpp NamedPipeSender.h
	$(CXX) $(CXXFLAGS) -c NamedPipeSender.cpp

NamedPipeReceiver.o: NamedPipeReceiver.cpp NamedPipeReceiver.h
	$(CXX) $(CXXFLAGS) -c NamedPipeReceiver.cpp

clean:
	rm -f sender receiver sender.o receiver.o NamedPipeSender.o NamedPipeReceiver.o
