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

    const Figure& getFigureById(const GameObject::ObjectId& id) const;
    void addFigure(const Figure& figure);

    void write(MemoryStream& stream) const override;
    void read(MemoryStream& stream) override;
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
