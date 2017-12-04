#include <QApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QWidget>
#include <QQmlContext>
#include <QQmlEngine>
#include <QJSValueIterator>
#include <iostream>
#include <thread>

#include "ChessClient.h"
#include "GameController.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Chess::Client client;
    std::thread thread(&Chess::Client::serverHandler, &client);
    thread.detach();

    GameController gameController(client.getBoard());

    QQuickView view;
    view.rootContext()->setContextProperty("game", &gameController);
    view.setSource(QUrl(QStringLiteral("qrc:/qml/Board.qml")));
    gameController.setRootObject(view.rootObject());

    auto container = QWidget::createWindowContainer(&view);
    container->setMinimumSize(640, 640);
    container->setMaximumSize(640, 640);
    container->setFocusPolicy(Qt::TabFocus);
    container->setWindowTitle(QObject::tr("Chess"));
    container->show();
    return app.exec();
}
