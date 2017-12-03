#include <QApplication>
#include <QQuickView>
#include <QWidget>
#include <QQmlContext>
#include <iostream>
#include <thread>

#include "ChessServer.h"
#include "NetworkManager.h"
#include "ClientBoard.h"
#include "GameController.h"

namespace {

Client::Chess::Board board;

void clientMain() {
    NetworkManager *networkManager = requestNetworkManager();
    if (networkManager != nullptr) {
        networkManager->sendHeloPacket();

        while (1) {
            std::string packet = networkManager->receivePacket();
            MemoryStream stream(packet);

            try {
                switch (stream.readByte()) {
                    case PacketType::HELO:
                        std::cout << "Client id: " <<  stream.readString() << std::endl;
                        networkManager->sendStatePacket();
                        break;
                    case PacketType::REPLICATION:
                        board.read(stream);
                        break;
                }
            } catch (const std::exception&) {
            }
        }

        networkManager->Release();
    }

}

}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::thread thread(clientMain);
    thread.detach();

    GameController *gameController = new GameController;
    QObject::connect(&board, SIGNAL(boardChanged(const QString&)), gameController, SLOT(setPieces(const QString&)));

    QQuickView view;
    view.rootContext()->setContextProperty("game", gameController);
    view.setSource(QUrl(QStringLiteral("qrc:/qml/Board.qml")));

    auto container = QWidget::createWindowContainer(&view);
    container->setMinimumSize(640, 640);
    container->setMaximumSize(640, 640);
    container->setFocusPolicy(Qt::TabFocus);
    container->setWindowTitle(QObject::tr("Chess"));
    container->show();
    return app.exec();
}
