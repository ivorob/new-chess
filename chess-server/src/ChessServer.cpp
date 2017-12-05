#include <thread>
#include <chrono>
#include <iostream>
#include <list>

#include "ChessServer.h"
#include "ConcreteNetworkManager.h"
#include "Board.h"

namespace {

PacketQueue inQueue;
PacketQueue outQueue;

uint32_t clientId = 0;

std::vector<Chess::Board> clients;

typedef struct {
    uint32_t fromRow;
    uint32_t fromColumn;
    uint32_t toRow;
    uint32_t toColumn;
} moveType;

std::list<moveType> moves = {{6, 4, 4, 4}, {7, 1, 5, 2}, {6, 3, 5, 3}, {7, 2, 3, 6}};

void
serverMain()
{
    ConcreteNetworkManager networkManager(inQueue, outQueue);
    while (1) {
        std::string packet = networkManager.receivePacket();
        MemoryStream stream(packet);
        switch (stream.readByte()) {
            case PacketType::HELO:
                clients.push_back(Chess::createBoard());

                networkManager.sendHeloPacket(std::to_string(clientId));
                break;
            case PacketType::STATE:
                networkManager.sendReplicationPacket(clients[0]);
                break;
            case PacketType::REPLICATION:
                try {
                    Chess::Figure figure;
                    figure.read(stream);

                    if (clients[0].moveFigure(figure.getId(), figure.getRow(), figure.getColumn())) {
                        if (!moves.empty()) {
                            moveType move = moves.front();
                            moves.pop_front();
                            clients[0].moveFigure(move.fromRow, move.fromColumn, move.toRow, move.toColumn);

                            networkManager.sendReplicationPacket(clients[0]);
                        }
                    }
                } catch (const std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
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
