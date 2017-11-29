#include "Figure.h"

Chess::Figure::Figure(const GameObject::ObjectId& id,
               const std::string& classId,
               uint32_t row,
               uint32_t column,
               Color color
    ) : GameObject(id, classId),
        row(row),
        column(column),
        color(color)
{
}

uint32_t
Chess::Figure::getRow() const
{
    return this->row;
}

void
Chess::Figure::setRow(uint32_t row)
{
    this->row = row;
}

uint32_t
Chess::Figure::getColumn() const
{
    return this->column;
}

void
Chess::Figure::setColumn(uint32_t column)
{
    this->column = column;
}

Chess::Figure::Color
Chess::Figure::getColor() const
{
    return this->color;
}

void
Chess::Figure::setColor(Chess::Figure::Color color)
{
    this->color = color;
}

void
Chess::Figure::write(MemoryStream& stream)
{
    GameObject::write(stream);
    stream.write(getRow());
    stream.write(getColumn());
    stream.write(getColor());
}
