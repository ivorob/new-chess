#include "figures/Pawn.h"

Pawn::Pawn(const GameObject::ObjectId& id, Figure::Color color, uint32_t row, uint32_t column)
    : Figure(id, "P", row, column, color)
{
}
