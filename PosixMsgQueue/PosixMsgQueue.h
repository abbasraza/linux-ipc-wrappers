#ifndef POSIXMSGQUEUE_H
#define POSIXMSGQUEUE_H

#include <string>
#include <mqueue.h>

class PosixMsgQueue
{
public:
    PosixMsgQueue(const std::string &queueName, mode_t permissions = 0666, size_t maxMsgSize = 8192);
    virtual ~PosixMsgQueue();

    void sendMsg(const std::string &msg);
    std::string receiveMsg();

private:
    std::string m_queueName;
    mode_t m_permissions;
    size_t m_maxMsgSize;
    mqd_t m_queueDescriptor;
    struct mq_attr m_queueAttr;
};

#endif
