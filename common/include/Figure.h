#pragma once

#include "GameObject.h"
#include "GameConstants.h"

namespace Chess {

class Figure : public GameObject {
public:
    Figure();
    Figure(const GameObject::ObjectId& id,
           const std::string& classId,
           uint32_t row = 0,
           uint32_t column = 0,
           Color color = Color::White);

    uint32_t getRow() const;
    void setRow(uint32_t row);

    uint32_t getColumn() const;
    void setColumn(uint32_t column);

    Color getColor() const;
    void setColor(Color color);

    void write(MemoryStream& stream) const override;
    void read(MemoryStream& stream) override;
private:
    uint32_t row;
    uint32_t column;
    Color color;
};

}
