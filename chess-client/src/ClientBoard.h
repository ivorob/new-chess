#pragma once

#include <QObject>
#include "Board.h"

namespace Client {
namespace Chess {

class Board 
    : public QObject, 
      public ::Chess::Board
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr);

    void read(MemoryStream& stream) override;
signals:
    void boardChanged(const QString& state);
private:
    void updateState();
private:
    QString state;
};

}
}
