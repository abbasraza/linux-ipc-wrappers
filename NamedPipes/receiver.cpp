// Author: Abbas Raza
// Description: This program receives messages through a named pipe using the NamedPipeReceiver class.
//              The named pipe used is located at /tmp/myfifo.
//              The program receives multiple messages and displays them on the console.
//              To use this program, run the corresponding sender program to send messages through the named pipe.

#include <iostream>
#include <string>
#include "NamedPipeReceiver.h"

int main()
{
    // Name for the named pipe
    std::string pipeName = "/tmp/myfifo";

    // Create a receiver
    NamedPipeReceiver receiver(pipeName);

    // Receive the message
    std::string receivedMessage = receiver.receiveMessage();

    // Display the received message
    std::cout << "Received Message: " << receivedMessage << std::endl;

    // Receive more messages
    std::cout << "Received Message: " << receiver.receiveMessage() << std::endl;
    std::cout << "Received Message: " << receiver.receiveMessage() << std::endl;
    std::cout << "Received Message: " << receiver.receiveMessage() << std::endl;


    return 0;
}
