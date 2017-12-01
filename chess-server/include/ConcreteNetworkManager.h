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
    void Release();
private:
    PacketQueue& inQueue;
    PacketQueue& outQueue;
};
