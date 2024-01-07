#include "ipc_writer.h"
#include <mqueue.h>
#include <thread>

IPCWriter::IPCWriter(std::string const &queueName)
    : mq_{}, last_sent_time_{std::chrono::steady_clock::now()}
{
    mq_unlink(queueName.c_str());
    mq_ = mq_open(queueName.c_str(), O_CREAT | O_WRONLY, 0666, nullptr);
    if (mq_ == -1)
    {
        // log("ERROR: Could not open queue with name:" + queueName);
    }
}

IPCWriter::~IPCWriter()
{
    mq_close(mq_);
}

void IPCWriter::send(std::string const &message, int fps)
{
    auto const end = std::chrono::steady_clock::now();
    auto const elapsedTime =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - last_sent_time_);

    // Make the delay between sending messages 1000ms/fps of a second
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps) - elapsedTime);

    if (!send(message))
    {
        // log("ERROR: Could not send message: " + message);
    }
    last_sent_time_ = std::chrono::steady_clock::now();
}

bool IPCWriter::send(std::string const &message)
{
    int const result = mq_send(mq_, message.c_str(), message.size(), 0);
    return result != -1;
}
