#pragma once

#include <cstdint>
#include <memory>

class IMessage
{
public:

    virtual std::uint32_t getMessageId() const = 0;
};
