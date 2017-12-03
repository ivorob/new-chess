#pragma once

#include <QObject>
#include "ClientBoard.h"

class GameController : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString pieces READ getPieces WRITE setPieces NOTIFY piecesChanged)
public:
    const QString& getPieces() const;
public slots:
    void setPieces(const QString& pieces);
signals:
    void piecesChanged(const QString& pieces);
private:
    QString pieces;
};
