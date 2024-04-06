#pragma once
#include <string>
#include "Hero1.h"

class Trap {
private:
    std::string name;
    char symbol;
    int damage;

public:
    Trap(const std::string& trapName, char trapSymbol, int trapDamage);
    ~Trap();
    char getSymbol() const;
    void getDamageFromTrap(Hero& target);
};

