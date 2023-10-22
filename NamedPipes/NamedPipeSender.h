#pragma once
#include <string>
#include <sys/stat.h>

/**
 * @brief A class for sending messages through a named pipe.
 * 
 */
class NamedPipeSender
{
public:
    /**
     * @brief Construct a new Named Pipe Sender object.
     * 
     * @param pipeName The name of the named pipe to send messages through.
     */
    NamedPipeSender(const std::string &pipeName);

    /**
     * @brief Destroy the Named Pipe Sender object.
     * 
     */
    virtual ~NamedPipeSender();

    /**
     * @brief Send a message through the named pipe.
     * Blocks until the receiver opens the pipe for reading.
     * @param message The message to send.
     */
    void sendMessage(const std::string &message);

private:
    /**
     * @brief The permissions to use when creating the named pipe.
     * 
     */
    static const mode_t PIPE_PERMISSIONS = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    /**
     * @brief The name of the named pipe to send messages through.
     * 
     */
    std::string m_pipeName;
};
