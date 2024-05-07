#include "Trap1.h"
#include <iostream>

Trap::Trap(const std::string& trapName, char trapSymbol, int trapDamage)
    : damage(trapDamage) {
    name = trapName;
    symbol = trapSymbol;
}

Trap::~Trap() {
    std::cout << "Trap " << name << " has been triggered..." << std::endl;
}

int Trap::getDamage() const {
    return damage;
}
