#ifndef IPC_WRITER_H
#define IPC_WRITER_H

#include <mqueue.h>
#include <chrono>
#include <string>

class IPCWriter
{
public:
    IPCWriter(std::string const &queueName);
    ~IPCWriter();

    void send(std::string const &message, int fps);

private:
    bool send(std::string const &message);

    mqd_t mq_;                                             // handle of posix queue
    std::chrono::steady_clock::time_point last_sent_time_; // last time message sent
};

#endif // IPC_WRITER_H