#include <thread>
#include <iostream>
#include "ChessServer.h"
#include "ConcreteNetworkManager.h"

namespace {

PacketQueue inQueue;
PacketQueue outQueue;

void
serverMain()
{
    ConcreteNetworkManager manager(inQueue, outQueue);
    manager.sendPacket("HELO");
}

}

extern "C"
NetworkManager *requestNetworkManager()
{
    std::thread serverMainThread(serverMain);
    serverMainThread.detach();

    return new ConcreteNetworkManager(outQueue, inQueue);
}
