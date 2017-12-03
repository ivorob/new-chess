#include "GameController.h"

const QString&
GameController::getPieces() const
{
    return this->pieces;
}

void
GameController::setPieces(const QString& pieces)
{
    this->pieces = pieces;
    emit piecesChanged(this->pieces);
}
