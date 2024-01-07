#ifndef IPC_READER_H
#define IPC_READER_H

#include <chrono>
#include <functional>
#include <mqueue.h>
#include <string>

class IPCReader
{
    using UpdateFunction = std::function<void(int)>;

public:
    IPCReader(std::string const &queueName, int fps, UpdateFunction callback);
    ~IPCReader();

    void receiveMessages();

private:
    std::string receive();

    mqd_t mq_;                                             // posix queue handle
    std::string mq_name_;                                  // posix queue name
    std::chrono::steady_clock::time_point last_sent_time_; // last time message read
    int fps_;                                              // frequency of reading in
                                                           // frames per second
    UpdateFunction updateFunc_;                            // callback function to update the client of reader
};

#endif // IPC_READER_H
