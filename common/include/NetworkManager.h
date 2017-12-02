#pragma once

#include <string>
#include "GameObject.h"

typedef enum {
    HELO = 0,
    STATE,
    REPLICATION,
} PacketType;

class NetworkManager  {
public:
    virtual ~NetworkManager() = default;

    virtual std::string receivePacket() = 0;

    virtual void sendPacket(const std::string& packet) = 0;
    virtual void sendReplicationPacket(const GameObject& gameObject) = 0;
    virtual void sendHeloPacket(const std::string& clientId = std::string()) = 0;
    virtual void sendStatePacket() = 0;

    virtual void Release() = 0;
};
