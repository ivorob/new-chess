#include <chrono>

#include "ConcreteNetworkManager.h"
#include "MemoryStream.h"

ConcreteNetworkManager::ConcreteNetworkManager(PacketQueue& inQueue, PacketQueue& outQueue)
    : inQueue(inQueue),
      outQueue(outQueue)
{
}

std::string
ConcreteNetworkManager::receivePacket()
{
    while (inQueue.empty()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return inQueue.pop();
}

void
ConcreteNetworkManager::sendPacket(const std::string& packet)
{
    outQueue.push(packet);
}

void
ConcreteNetworkManager::Release()
{
    delete this;
}

void
ConcreteNetworkManager::sendReplicationPacket(const GameObject& gameObject)
{
    MemoryStream stream;
    stream.write(PacketType::REPLICATION);
    gameObject.write(stream);
    sendPacket(stream.getData());
}
