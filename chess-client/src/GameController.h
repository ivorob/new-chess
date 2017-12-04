#pragma once

#include <QObject>
#include "ClientBoard.h"

class GameController : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString pieces READ getPieces WRITE setPieces NOTIFY piecesChanged)
public:
    GameController(Client::Chess::Board& board, QObject *parent = nullptr);

    const QString& getPieces() const;

    void setRootObject(QObject *object);

    Q_INVOKABLE bool isPosibleMove(QObject *object, int cellIndex) const;
    Q_INVOKABLE void makeMove(QObject *object, int fromIndex, int toIndex);
public slots:
    void setPieces(const QString& pieces);
signals:
    void piecesChanged(const QString& pieces);
private:
    Client::Chess::Board& board;
    QString pieces;
    int moveColor;
    QObject *rootObject;
};
