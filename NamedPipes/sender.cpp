
// Author: Abbas Raza
// Description: This program sends a message through a named pipe using the NamedPipeSender class.
//              The named pipe used is located at /tmp/myfifo.
//              The message sent is "Hello, Named Pipes!".
#include <iostream>
#include <string>
#include "NamedPipeSender.h"
#include <unistd.h>

int main()
{
    // Name for the named pipe
    std::string pipeName = "/tmp/myfifo";

    // Create a sender
    NamedPipeSender sender(pipeName);

    // Message to be sent
    std::string messageToSend = "Hello, Named Pipes!";

    // Send the message
    sender.sendMessage(messageToSend);

    std::cout << "Message sent: " << messageToSend << std::endl;

    return 0;
}
