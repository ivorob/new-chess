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

    updateState();
}

void
Client::Chess::Board::updateState()
{
    QString newState;
    newState.fill(' ', getRows() * getColumns());

    for (const auto& figure : this->figures) {
        char letter = figure.getClassId()[0];

        if (figure.getColor() == ::Chess::Figure::Color::Black) {
            letter += 0x20;
        }

        newState[figure.getRow() * 8 + figure.getColumn()] = letter;
    }

    QString reverseState;
    std::reverse_copy(newState.begin(), newState.end(), std::back_inserter(reverseState));

    if (reverseState != this->state) {
        this->state = reverseState;
        emit boardChanged(this->state);
    }
}
