#pragma once

#include <memory>

class IMessage;

class Scheduler
{
public:
    virtual void send(std::unique_ptr<IMessage>) = 0;
};
