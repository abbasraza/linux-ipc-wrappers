// Author: Abbas Raza
// Description: This program sends a message to POSIX message queue named "/posix_mq".

#include "PosixMsgQueue.h"
#include <iostream>

int main()
{
    // Create a message queue named "my_queue" with read and write permissions
    PosixMsgQueue msqQueue("/posix_mq");

    // Send a message
    msqQueue.sendMsg("Hello, this is a message from the sender!");

    std::cout << "Msg sent." << std::endl;

    // Keep the program running to prevent the queue from being destroyed
    // queue will be destroyed when msqQueue goes out of scope
    while(1);

    return 0;
}
