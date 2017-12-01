#include <QApplication>
#include <QQuickView>
#include <QWidget>
#include <QQmlContext>
#include <iostream>

#include "ChessServer.h"
#include "NetworkManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    NetworkManager *networkManager = requestNetworkManager();
    if (networkManager != nullptr) {
        std::string packet = networkManager->receivePacket();
        std::cerr << "packet: " << packet << std::endl;
        networkManager->Release();
    }

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:/qml/Board.qml")));

    auto container = QWidget::createWindowContainer(&view);
    container->setMinimumSize(640, 640);
    container->setMaximumSize(640, 640);
    container->setFocusPolicy(Qt::TabFocus);
    container->setWindowTitle(QObject::tr("Chess"));
    container->show();
    return app.exec();
}
