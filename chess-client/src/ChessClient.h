#pragma once

#include <QObject>
#include "NetworkManager.h"
#include "ClientBoard.h"

namespace Chess {

class Client : public QObject {
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    ::Client::Chess::Board& getBoard();

    void serverHandler();
public slots:
    void sendReplicationPacket(uint32_t figureId);
private:
    ::Client::Chess::Board board;
    std::string clientId;
    NetworkManager *networkManager;
    QObject *rootObject;
};

}
