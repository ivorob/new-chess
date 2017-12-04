#include <QDebug>
#include "ChessClient.h"
#include "ChessServer.h"

Chess::Client::Client(QObject *parent)
    : QObject(parent),
      networkManager(requestNetworkManager())
{
    QObject::connect(&board, SIGNAL(boardChangedFromClient(uint32_t)), this, SLOT(sendReplicationPacket(uint32_t)));
}

Client::Chess::Board&
Chess::Client::getBoard()
{
    return this->board;
}

void
Chess::Client::serverHandler()
{
    if (this->networkManager != nullptr) {
        this->networkManager->sendHeloPacket();

        while (1) {
            std::string packet = this->networkManager->receivePacket();
            MemoryStream stream(packet);

            try {
                switch (stream.readByte()) {
                    case PacketType::HELO:
                        this->clientId = stream.readString();
                        this->networkManager->sendStatePacket();
                        break;
                    case PacketType::REPLICATION:
                        if (stream.pickByte() == 0) {
                            board.read(stream);
                        } 
                        break;
                }
            } catch (const std::exception& e) {
                qDebug() << e.what();
            }
        }

        this->networkManager->Release();
    }
}

void
Chess::Client::sendReplicationPacket(uint32_t figureId)
{
    try {
        const Chess::Figure& figure = board.getFigureById(figureId);
        this->networkManager->sendReplicationPacket(figure);
    } catch (const std::runtime_error& error) {
        qDebug() << error.what();
    }
}
