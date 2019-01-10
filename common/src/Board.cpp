#include <algorithm>
#include "Board.h"
#include "Figures.h"
#include "GameConstants.h"

Chess::Board::Board()
    : rows(),
      columns(),
      color(Chess::Color::White)
{
}

Chess::Board::Board(uint32_t rows, uint32_t columns, Color color)
    : GameObject(0, "BOARD"),
      rows(rows),
      columns(columns),
      color(color)
{
}

uint32_t
Chess::Board::getRows() const
{
    return this->rows;
}

uint32_t
Chess::Board::getColumns() const
{
    return this->columns;
}

Chess::Figure&
Chess::Board::getFigureById(const GameObject::ObjectId& id)
{
    const auto& it = std::find_if(
        this->figures.begin(),
        this->figures.end(),
        [id] (const Figure& item) -> bool {
            return id == item.getId();
        }
    );

    if (it == this->figures.end()) {
        throw Chess::BoardException("Cannot find figure with id: " + std::to_string(id));
    } 

    return *it;
}

void
Chess::Board::addFigure(const Figure& figure)
{
    const auto& it = std::find_if(
        this->figures.begin(),
        this->figures.end(),
        [&figure] (const Figure& item) -> bool {
            return figure.getId() == item.getId();
        }
    );

    if (it == this->figures.end()) {
        this->figures.push_back(figure);
    }
}

Chess::Color
Chess::Board::getMoveColor() const
{
    return this->color;
}

void
Chess::Board::setMoveColor(Color color)
{
    this->color = color;
}


bool
Chess::Board::moveFigure(uint32_t fromRow, uint32_t fromColumn, uint32_t toRow, uint32_t toColumn)
{
    auto fromIt = getFigureByCoordinate(fromRow, fromColumn);
    if (fromIt != this->figures.end()) {
        auto toIt = getFigureByCoordinate(toRow, toColumn);
        if (toIt != this->figures.end()) {
            this->figures.erase(toIt);
        }

        fromIt->setRow(toRow);
        fromIt->setColumn(toColumn);
    }

    return false;
}

std::list<Chess::Figure>::iterator
Chess::Board::getFigureByCoordinate(uint32_t row, uint32_t column)
{
    auto it = this->figures.begin();
    while (it != this->figures.end()) {
        if (it->getRow() == row &&
            it->getColumn() == column)
        {
            return it;
        }

        ++it;
    }

    return this->figures.end();
}

bool
Chess::Board::moveFigure(const GameObject::ObjectId& objectId, uint32_t toRow, uint32_t toColumn)
{
    const auto& it = std::find_if(
        this->figures.begin(),
        this->figures.end(),
        [objectId] (const Figure& item) -> bool {
            return objectId == item.getId();
        }
    );

    if (it != this->figures.end()) {
        auto toIt = getFigureByCoordinate(toRow, toColumn);
        if (toIt != this->figures.end()) {
            this->figures.erase(toIt);
        }

        it->setRow(toRow);
        it->setColumn(toColumn);
        return true;
    }

    return false;
}

void
Chess::Board::write(MemoryStream& stream) const
{
    GameObject::write(stream);
    stream.write(getRows());
    stream.write(getColumns());
    stream.write(getMoveColor());
    stream.write(static_cast<uint32_t>(this->figures.size()));

    for (const auto& figure : this->figures) {
        figure.write(stream);
    }
}

void
Chess::Board::read(MemoryStream& stream)
{
    this->figures.clear();

    GameObject::read(stream);
    this->rows = stream.readUint32();
    this->columns = stream.readUint32();
    this->color = static_cast<Chess::Color>(stream.readUint32());
    uint32_t size = stream.readUint32();

    for (uint32_t i = 0; i < size; ++i) {
        Chess::Figure figure;
        figure.read(stream);
        addFigure(figure);
    }
}

Chess::MoveValidator
Chess::Board::makeMoveValidator() const
{
    MoveValidator validator;
    for (const auto& figure : this->figures) {
        validator.addFigure(figure);
    }

    validator.print(0);
    return validator;
}

// BoardException
Chess::BoardException::BoardException(const std::string& what)
    : std::exception(what.c_str())
{
}

Chess::Board
Chess::createBoard()
{
    Chess::Board board(8, 8);

    uint32_t id = 0;

    // white figures
    for (uint32_t i = 0; i < 8; ++i) {
        board.addFigure(Chess::Pawn(++id, Chess::Color::White, 1, i));
    }

    board.addFigure(Chess::Rook(++id, Chess::Color::White, 0, 0));
    board.addFigure(Chess::Rook(++id, Chess::Color::White, 0, 7));

    board.addFigure(Chess::Knight(++id, Chess::Color::White, 0, 1));
    board.addFigure(Chess::Knight(++id, Chess::Color::White, 0, 6));

    board.addFigure(Chess::Bishop(++id, Chess::Color::White, 0, 2));
    board.addFigure(Chess::Bishop(++id, Chess::Color::White, 0, 5));

    board.addFigure(Chess::Queen(++id, Chess::Color::White, 0, 3));
    board.addFigure(Chess::King(++id, Chess::Color::White, 0, 4));

    for (uint32_t i = 0; i < 8; ++i) {
        board.addFigure(Chess::Pawn(++id, Chess::Color::Black, 6, i));
    }

    board.addFigure(Chess::Rook(++id, Chess::Color::Black, 7, 0));
    board.addFigure(Chess::Rook(++id, Chess::Color::Black, 7, 7));

    board.addFigure(Chess::Knight(++id, Chess::Color::Black, 7, 1));
    board.addFigure(Chess::Knight(++id, Chess::Color::Black, 7, 6));

    board.addFigure(Chess::Bishop(++id, Chess::Color::Black, 7, 2));
    board.addFigure(Chess::Bishop(++id, Chess::Color::Black, 7, 5));

    board.addFigure(Chess::Queen(++id, Chess::Color::Black, 7, 3));
    board.addFigure(Chess::King(++id, Chess::Color::Black, 7, 4));

    return board;
}
