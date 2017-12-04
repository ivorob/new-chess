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
    void moveFigure(uint32_t rowFrom, uint32_t columnFrom,
            uint32_t rowTo, uint32_t columnTo);
signals:
    void boardChangedFromServer(const QString& state);
    void boardChangedFromClient(uint32_t id);
private:
    bool updateState();
    ::Chess::Figure& getByPosition(uint32_t row, uint32_t column);
private:
    QString state;
};

}
}
