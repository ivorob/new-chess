#pragma once

#include "NetworkManager.h"
#include "SafeThreadQueue.h"

typedef SafeThreadQueue<std::string> PacketQueue;

class ConcreteNetworkManager : public NetworkManager {
public:
    ConcreteNetworkManager(PacketQueue& inQueue, PacketQueue& outQueue);

    std::string receivePacket() override;

    void sendPacket(const std::string& packet) override;
    void sendReplicationPacket(const GameObject& gameObject) override;
    void sendHeloPacket(const std::string& clientId) override;
    void sendStatePacket() override;

    void Release() override;
private:
    PacketQueue& inQueue;
    PacketQueue& outQueue;
};
