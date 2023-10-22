
// Author: Abbas Raza
// Description: This program receives a message from a POSIX message queue named "/posix_mq".

#include "PosixMsgQueue.h"
#include <iostream>

int main()
{
    // Open the message queue named "/posix_mq" with read and write permissions
    PosixMsgQueue msgQueue("/posix_mq");

    // Receive a message
    std::string message = msgQueue.receiveMsg();

    std::cout << "Received message: " << message << std::endl;

    return 0;
}
