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

Chess::Figure::Figure()
    : GameObject(),
      row(),
      column(),
      color(Color::White)
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

Chess::Color
Chess::Figure::getColor() const
{
    return this->color;
}

void
Chess::Figure::setColor(Chess::Color color)
{
    this->color = color;
}

void
Chess::Figure::write(MemoryStream& stream) const
{
    GameObject::write(stream);
    stream.write(getRow());
    stream.write(getColumn());
    stream.write(getColor());
}

void
Chess::Figure::read(MemoryStream& stream)
{
    GameObject::read(stream);
    this->row = stream.readUint32();
    this->column = stream.readUint32();
    this->color = static_cast<Color>(stream.readUint32());
}
