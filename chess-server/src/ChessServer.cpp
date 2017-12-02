#include <thread>
#include <chrono>
#include <iostream>

#include "ChessServer.h"
#include "ConcreteNetworkManager.h"
#include "Board.h"

namespace {

PacketQueue inQueue;
PacketQueue outQueue;

uint32_t clientId = 0;

std::vector<Chess::Board> clients;

void
serverMain()
{
    ConcreteNetworkManager networkManager(inQueue, outQueue);
    while (1) {
        std::string packet = networkManager.receivePacket();
        switch (packet[0]) {
            case PacketType::HELO:
                clients.push_back(Chess::Board(8, 8));

                networkManager.sendHeloPacket(std::to_string(clientId));
                break;
            case PacketType::STATE:
                networkManager.sendReplicationPacket(clients[0]);
                break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

}

extern "C"
NetworkManager *requestNetworkManager()
{
    std::thread serverMainThread(serverMain);
    serverMainThread.detach();

    return new ConcreteNetworkManager(outQueue, inQueue);
}
