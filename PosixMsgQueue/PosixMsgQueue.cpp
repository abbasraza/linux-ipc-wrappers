//
// Author: Abbas Raza
//
// Description:
// This file contains the implementation of the PosixMsgQueue class
// which provides a wrapper around the POSIX message queue API.
// The class allows users to create, open, send, and receive messages
// from a POSIX message queue.
//

#include "PosixMsgQueue.h"
#include <iostream>

// Constructor
PosixMsgQueue::PosixMsgQueue(const std::string &queueName, mode_t permissions, size_t maxMsgSize)
    : m_queueName(queueName), m_permissions(permissions), m_maxMsgSize(maxMsgSize)
{
    // Initialize the queue attributes
    m_queueAttr.mq_flags = 0;
    m_queueAttr.mq_maxmsg = 10;
    m_queueAttr.mq_msgsize = maxMsgSize;
    m_queueAttr.mq_curmsgs = 0;

    // Open or create the msg queue
    // if queue already exists, open it otherwise create it
    m_queueDescriptor = mq_open(queueName.c_str(), O_CREAT | O_RDWR, permissions, &m_queueAttr);
    if (m_queueDescriptor == (mqd_t)-1)
    {
        std::cerr << "Error opening/creating the msg queue." << std::endl;
        exit(1);
    }
}

// Destructor
PosixMsgQueue::~PosixMsgQueue()
{
    // Close and unlink the msg queue
    
    // mq_close will only close the descriptor
    mq_close(m_queueDescriptor);

    /*
    mq_unlink() removes the specified message queue name.
    The message queue name is removed immediately. The queue itself
    is destroyed once any other processes that have the queue open; close their
    descriptors referring to the queue.
    All the messages remaining on the queue are lost.
    */
    mq_unlink(m_queueName.c_str());
}

// Send a message to the queue
void PosixMsgQueue::sendMsg(const std::string &msg)
{
    if (msg.length() >= m_maxMsgSize)
    {
        std::cerr << "Msg size exceeds the maximum allowed size." << std::endl;
        return;
    }

    if (mq_send(m_queueDescriptor, msg.c_str(), msg.length(), 0) == -1)
    {
        std::cerr << "Error sending a msg to the queue." << std::endl;
    }
}

// Receive a message from the queue
std::string PosixMsgQueue::receiveMsg()
{
    char buffer[m_maxMsgSize];
    ssize_t bytesReceived = mq_receive(m_queueDescriptor, buffer, m_maxMsgSize, nullptr);
    if (bytesReceived == -1)
    {
        std::cerr << "Error receiving a msg from the queue." << std::endl;
        return "";
    }
    buffer[bytesReceived] = '\0'; // Null-terminate the received msg
    return std::string(buffer);
}
