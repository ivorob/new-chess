#pragma once

#include <vector>

#include "GameObject.h"
#include "GameConstants.h"
#include "Figure.h"

namespace Chess {

class Board : public GameObject {
public:
    Board();
    Board(uint32_t rows, uint32_t columns, Color color = Chess::Color::White);

    uint32_t getRows() const;
    uint32_t getColumns() const;

    Chess::Color getMoveColor() const;
    void setMoveColor(Color color);

    Figure& getFigureById(const GameObject::ObjectId& id);
    void addFigure(const Figure& figure);

    void write(MemoryStream& stream) const override;
    void read(MemoryStream& stream) override;

    bool moveFigure(uint32_t fromRow, uint32_t fromColumn, uint32_t toRow, uint32_t toColumn);
    bool moveFigure(const GameObject::ObjectId& objectId, uint32_t toRow, uint32_t toColumn);
private:
    uint32_t rows;
    uint32_t columns;
    Chess::Color color;
protected:
    std::vector<Figure> figures;
};

class BoardException : public std::exception {
public:
    BoardException(const std::string& what);
};

Board createBoard();

}
