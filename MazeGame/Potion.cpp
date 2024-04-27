#include "Potion1.h"
#include <iostream>

Potion::Potion(const std::string& potionName, char potionSymbol, int healthGain)
    : health(healthGain) {
    name = potionName;
    symbol = potionSymbol;
}

Potion::~Potion() {
    std::cout << "Potion " << name << " has been consumed." << std::endl;
}

int Potion::getHealth() const {
    return health;
}
