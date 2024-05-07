#pragma once
#include <string>
#include "Item1.h"

class Trap : public Item {
private:
    int damage;

public:
    Trap(const std::string& trapName, char trapSymbol, int trapDamage);
    ~Trap();
    int getDamage() const;
    ElementType getType() override {
        return ElementType::Trap;
    }
};
///