#pragma once
#include <string>
#include "Item1.h"

class Potion : Item {
private:

    int health;

public:
    Potion(const std::string& potionName, char potionSymbol, int healthGain);
    ~Potion();
    int getHealth() const;
};