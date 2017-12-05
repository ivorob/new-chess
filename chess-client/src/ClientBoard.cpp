#include <QDebug>
#include <iostream>
#include "ClientBoard.h"

Client::Chess::Board::Board(QObject *parent)
    : QObject(parent)
{
}

void
Client::Chess::Board::read(MemoryStream& stream)
{
    ::Chess::Board::read(stream);

    if (updateState()) {
        emit boardChangedFromServer(this->state);
    }
}

bool 
Client::Chess::Board::updateState()
{
    QString newState;
    newState.fill(' ', getRows() * getColumns());

    for (const auto& figure : this->figures) {
        char letter = figure.getClassId()[0];

        if (figure.getColor() == ::Chess::Color::Black) {
            letter += 0x20;
        }

        newState[56 - figure.getRow() * 8 + figure.getColumn()] = letter;
    }

    if (newState != this->state) {
        this->state = newState;
        return true;
    }

    return false;
}

void
Client::Chess::Board::moveFigure(
    uint32_t rowFrom,
    uint32_t columnFrom,
    uint32_t rowTo,
    uint32_t columnTo)
{
    try {
        ::Chess::Figure& figure = getByPosition(rowFrom, columnFrom);
        figure.setRow(rowTo);
        figure.setColumn(columnTo);

        updateState();
        qDebug() << "update figure: " << QString(figure.getId());
        emit boardChangedFromClient(figure.getId());
    } catch (const std::runtime_error& error) {
        qDebug() << error.what();
    }
}

Chess::Figure&
Client::Chess::Board::getByPosition(uint32_t row, uint32_t column)
{
    for (auto& figure : this->figures) {
        if (figure.getRow() == row &&
            figure.getColumn() == column)
        {
            return figure;
        }
    }

    throw std::runtime_error("Figure with position [" + std::to_string(row) 
            + "; " + std::to_string(column) + " isn't found!");
}
