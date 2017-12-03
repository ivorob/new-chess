#include <algorithm>
#include "Board.h"
#include "Figures.h"

Chess::Board::Board()
    : rows(),
      columns()
{
}

Chess::Board::Board(uint32_t rows, uint32_t columns)
    : GameObject(0, "BOARD"),
      rows(rows),
      columns(columns)
{
    this->figures.reserve(32);
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

const Chess::Figure&
Chess::Board::getFigureById(const GameObject::ObjectId& id) const
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

void
Chess::Board::write(MemoryStream& stream) const
{
    GameObject::write(stream);
    stream.write(getRows());
    stream.write(getColumns());
    stream.write(static_cast<uint32_t>(this->figures.size()));

    for (const auto& figure : this->figures) {
        figure.write(stream);
    }
}

void
Chess::Board::read(MemoryStream& stream)
{
    GameObject::read(stream);
    this->rows = stream.readUint32();
    this->columns = stream.readUint32();
    uint32_t size = stream.readUint32();

    for (uint32_t i = 0; i < size; ++i) {
        Chess::Figure figure;
        figure.read(stream);
        addFigure(figure);
    }
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
        board.addFigure(Chess::Pawn(++id, Chess::Figure::Color::White, 1, i));
    }

    board.addFigure(Chess::Rook(++id, Chess::Figure::Color::White, 0, 0));
    board.addFigure(Chess::Rook(++id, Chess::Figure::Color::White, 0, 7));

    board.addFigure(Chess::Knight(++id, Chess::Figure::Color::White, 0, 1));
    board.addFigure(Chess::Knight(++id, Chess::Figure::Color::White, 0, 6));

    board.addFigure(Chess::Bishop(++id, Chess::Figure::Color::White, 0, 2));
    board.addFigure(Chess::Bishop(++id, Chess::Figure::Color::White, 0, 5));

    board.addFigure(Chess::Queen(++id, Chess::Figure::Color::White, 0, 3));
    board.addFigure(Chess::King(++id, Chess::Figure::Color::White, 0, 4));

    for (uint32_t i = 0; i < 8; ++i) {
        board.addFigure(Chess::Pawn(++id, Chess::Figure::Color::Black, 6, i));
    }

    board.addFigure(Chess::Rook(++id, Chess::Figure::Color::Black, 7, 0));
    board.addFigure(Chess::Rook(++id, Chess::Figure::Color::Black, 7, 7));

    board.addFigure(Chess::Knight(++id, Chess::Figure::Color::Black, 7, 1));
    board.addFigure(Chess::Knight(++id, Chess::Figure::Color::Black, 7, 6));

    board.addFigure(Chess::Bishop(++id, Chess::Figure::Color::Black, 7, 2));
    board.addFigure(Chess::Bishop(++id, Chess::Figure::Color::Black, 7, 5));

    board.addFigure(Chess::Queen(++id, Chess::Figure::Color::Black, 7, 3));
    board.addFigure(Chess::King(++id, Chess::Figure::Color::Black, 7, 4));

    return board;
}
