#include <QDebug>
#include "GameController.h"
#include "GameConstants.h"

GameController::GameController(Client::Chess::Board& board, QObject *parent)
    : QObject(parent),
      board(board),
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
        if (board.getMoveColor() == Chess::Color::White) {
            qDebug() << "TODO: validate cellIndex" << cellIndex;
            return true;
        }

        qDebug() << "TODO: validate cellIndex" << cellIndex;
        return false;
    } 

    qDebug() << "TODO: validate cellIndex" << cellIndex;
    return board.getMoveColor() == Chess::Color::Black;
}

void
GameController::makeMove(QObject *object, int fromIndex, int toIndex)
{
    board.moveFigure(7 - fromIndex / 8, fromIndex % 8, 7 - toIndex / 8, toIndex % 8);
    qDebug() << fromIndex << toIndex;
    if (board.getMoveColor() != Chess::Color::White) {
        board.setMoveColor(Chess::Color::White);
    } else {
        board.setMoveColor(Chess::Color::Black);
    }
}
