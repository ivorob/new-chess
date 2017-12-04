#include <QDebug>
#include "GameController.h"

GameController::GameController(Client::Chess::Board& board, QObject *parent)
    : QObject(parent),
      board(board),
      moveColor(0),
      rootObject()
{
    QObject::connect(&this->board, SIGNAL(boardChangedFromServer(const QString&)), this, SLOT(setPieces(const QString&)));
}

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

    QMetaObject::invokeMethod(this->rootObject, "update", Qt::DirectConnection);
}

void
GameController::setRootObject(QObject *object)
{
    this->rootObject = object;
}

bool
GameController::isPosibleMove(QObject *object, int cellIndex) const
{
    QObject *piece = object->parent()->parent();
    QString classId = piece->property("letter").toString();
    if (classId.toUpper() == classId) {
        if (moveColor == 0) {
            qDebug() << "TODO: validate cellIndex" << cellIndex;
            return true;
        }

        qDebug() << "TODO: validate cellIndex" << cellIndex;
        return false;
    } 

    qDebug() << "TODO: validate cellIndex" << cellIndex;
    return moveColor == 1;
}

void
GameController::makeMove(QObject *object, int fromIndex, int toIndex)
{
    board.moveFigure(7 - fromIndex / 8, fromIndex % 8, 7 - toIndex / 8, toIndex % 8);
    qDebug() << fromIndex << toIndex;
    moveColor = (moveColor != 0) ? 0 : 1;
}
