#pragma once

#include "IMessage.hpp"

template <class T>
class Message : public IMessage
{
public:
    Message(const T& payload = T())
        : m_payload(std::make_unique<T>(payload))
    {}

    std::uint32_t getMessageId() const override { return T::MESSAGE_ID; };

private:
    std::unique_ptr<T> m_payload;
};
