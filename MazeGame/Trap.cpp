#include "Trap1.h"
#include <iostream>

Trap::Trap(const std::string& trapName, char trapSymbol, int trapDamage)
    : name(trapName), symbol(trapSymbol), damage(trapDamage) {}

Trap::~Trap() {
    std::cout << "Trap " << name << " has been triggered." << std::endl;
}

char Trap::getSymbol() const {
    return symbol;
}

void Trap::getDamageFromTrap(Hero& target) {
    target.takeDamage(damage);
    std::cout << target.getName() << " triggered " << name << " and took " << damage << " damage." << std::endl;
}