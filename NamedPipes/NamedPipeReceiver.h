#pragma once
#include <string>
#include <sys/stat.h>

/**
 * @brief A class for receiving messages from a named pipe.
 * 
 */
class NamedPipeReceiver
{
public:
    /**
     * @brief Construct a new Named Pipe Receiver object
     * 
     * @param pipeName The name of the named pipe to receive messages from.
     */
    NamedPipeReceiver(const std::string &pipeName);

    /**
     * @brief Destroy the Named Pipe Receiver object
     * 
     */
    virtual ~NamedPipeReceiver();

    /**
     * @brief Receive a message from the named pipe.
     * Blocks until a message is received.
     * @return std::string The received message.
     */
    std::string receiveMessage();

private:
    /**
     * @brief The permissions for the named pipe.
     * 
     */
    static const mode_t PIPE_PERMISSIONS = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    /**
     * @brief The name of the named pipe.
     * 
     */
    std::string m_pipeName;
};
