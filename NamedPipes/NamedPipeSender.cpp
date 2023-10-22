#include "NamedPipeSender.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>

/**
 * Constructor for NamedPipeSender class.
 * Creates a named pipe with the given name if it doesn't already exist.
 * @param pipeName The name of the named pipe to create.
 */
NamedPipeSender::NamedPipeSender(const std::string &pipeName) : m_pipeName(pipeName)
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
 * Destructor for NamedPipeSender class.
 */
NamedPipeSender::~NamedPipeSender()
{
}

/**
 * Sends a message through the named pipe.
 * Blocks until the receiver opens the pipe for reading.
 * @param message The message to send through the named pipe.
 */
void NamedPipeSender::sendMessage(const std::string &message)
{
    FILE* pipe = fopen(m_pipeName.c_str(), "w");
    // fopen will block until the receiver opens the pipe for reading
    if (pipe != nullptr)
    {
        fprintf(pipe, "%s\n", message.c_str());
        fclose(pipe);
    }
    else
    {
        std::cerr << "Error writing to the named pipe." << std::endl;
    }
}
