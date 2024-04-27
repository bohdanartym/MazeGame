#pragma once
#include <string>
#include "Item1.h"

class Potion : public Item {
private:
    int health;

public:
    Potion(const std::string& potionName, char potionSymbol, int healthGain);
    ~Potion();
    int getHealth() const;
    ElementType getType() override {
        return ElementType::Potion;
    }
};
