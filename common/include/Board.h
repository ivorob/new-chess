#pragma once

#include <vector>

#include "GameObject.h"
#include "Figure.h"

namespace Chess {

class Board : public GameObject {
public:
    Board(uint32_t rows, uint32_t columns);

    uint32_t getRows() const;
    uint32_t getColumns() const;

    const Figure& getFigureById(const GameObject::ObjectId& id) const;
    void addFigure(const Figure& figure);

    void write(MemoryStream& stream) const override;
private:
    uint32_t rows;
    uint32_t columns;
    std::vector<Figure> figures;
};

class BoardException : public std::exception {
public:
    BoardException(const std::string& what);
};

}