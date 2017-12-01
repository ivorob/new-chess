#pragma once

#include <string>
#include "GameObject.h"

typedef enum {
    REPLICATION = 0,
} PacketType;

class NetworkManager  {
public:
    virtual ~NetworkManager() = default;

    virtual std::string receivePacket() = 0;

    virtual void sendPacket(const std::string& packet) = 0;
    virtual void sendReplicationPacket(const GameObject& gameObject) = 0;

    virtual void Release() = 0;
};
