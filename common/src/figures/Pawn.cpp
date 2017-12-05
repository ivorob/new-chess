#include "figures/Pawn.h"

Chess::Pawn::Pawn(const GameObject::ObjectId& id, Chess::Color color, uint32_t row, uint32_t column)
    : Figure(id, "P", row, column, color)
{
}
