#include "Figure.h"

Figure::Figure(const GameObject::ObjectId& id,
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
Figure::getRow() const
{
    return this->row;
}

void
Figure::setRow(uint32_t row)
{
    this->row = row;
}

uint32_t
Figure::getColumn() const
{
    return this->column;
}

void
Figure::setColumn(uint32_t column)
{
    this->column = column;
}

Figure::Color
Figure::getColor() const
{
    return this->color;
}

void
Figure::setColor(Figure::Color color)
{
    this->color = color;
}

void
Figure::write(MemoryStream& stream)
{
    GameObject::write(stream);
    stream.write(getRow());
    stream.write(getColumn());
    stream.write(getColor());
}
