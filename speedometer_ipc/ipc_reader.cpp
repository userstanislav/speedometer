#include "ipc_reader.h"
#include "ipc_settings.h"
#include <cstdlib>
#include <mqueue.h>
#include <string>
#include <thread>

IPCReader::IPCReader(std::string const &queueName, int fps, UpdateFunction callback)
    : mq_{}, mq_name_{queueName}, last_sent_time_{std::chrono::steady_clock::now()}, fps_{fps}, updateFunc_{callback}
{
    mq_ = mq_open(mq_name_.c_str(), O_CREAT | O_RDONLY, 0666, nullptr);
    if (mq_ == -1)
    {
        // log("ERROR: Could not open queue: " + mq_name_);
    }
}

IPCReader::~IPCReader()
{
    mq_close(mq_);
    mq_unlink(mq_name_.c_str());
}

void IPCReader::receiveMessages()
{
    for (;;)
    {
        auto const end = std::chrono::steady_clock::now();
        auto const elapsedTime =
            std::chrono::duration_cast<std::chrono::milliseconds>(end - last_sent_time_);

        // Make the delay between reading messages 1000ms/fps of a second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps) - elapsedTime);

        auto const data = receive();
        if (!data.empty())
        {
            updateFunc_(std::atoi(data.c_str()));
        }

        last_sent_time_ = std::chrono::steady_clock::now();
    }
}

std::string IPCReader::receive()
{
    char buffer[bufferSize + 1];
    size_t const bytesRead = mq_receive(mq_, buffer, bufferSize, nullptr);
    if (bytesRead > 0)
    {
        buffer[bytesRead] = '\0';
        return std::string(buffer);
    }
    return "";
}
