#pragma once

#include <gmock/gmock.h>

#include "Scheduler.hpp"

namespace project
{

class MockScheduler : public Scheduler
{
public:
    void send(std::unique_ptr<IMessage> msg) override { return send_test(*msg); }
    MOCK_METHOD1(send_test, void(IMessage const&));
};

} // namespace project
