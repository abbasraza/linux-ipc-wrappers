#include "NamedPipeReceiver.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * Constructor for NamedPipeReceiver class.
 * Creates a named pipe with the given name if it does not already exist.
 * @param pipeName The name of the named pipe.
 */
NamedPipeReceiver::NamedPipeReceiver(const std::string &pipeName) : m_pipeName(pipeName)
{
    if (access(pipeName.c_str(), F_OK) == -1)
    {
        if (mkfifo(pipeName.c_str(), PIPE_PERMISSIONS) == -1)
        {
            std::cerr << "Error creating the named pipe." << std::endl;
            exit(1);
        }
    }
    else
    {
        std::cerr << "Named pipe " << pipeName << " already exists.. using it !" << std::endl;
    }
}

/**
 * Destructor for NamedPipeReceiver class.
 */
NamedPipeReceiver::~NamedPipeReceiver()
{
}

/**
 * Receives a message from the named pipe.
 * Blocks until a message is received.
 * @return The received message as a string.
 */
std::string NamedPipeReceiver::receiveMessage()
{
    FILE* pipe = fopen(m_pipeName.c_str(), "r");
    // fopen will block until the sender opens the pipe for writing

    std::string message;

    if (pipe != nullptr)
    {
        char buffer[256];
        if (fgets(buffer, sizeof(buffer), pipe) != nullptr)
        {
            message = buffer;
        }
        else
        {
            std::cout << " fgets returned nullptr " << std::endl;
        }
        fclose(pipe);
    }
    else
    {
        std::cout << " fopen returned nullptr " << std::endl;
    }
    return message;
}
