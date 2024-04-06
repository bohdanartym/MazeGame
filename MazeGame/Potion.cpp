#include "Potion1.h"
#include <iostream>
using namespace std;

Potion::Potion(const std::string& potionName, char potionSymbol, int healthGain)
    : name(potionName), symbol(potionSymbol), health(healthGain) {}

Potion::~Potion() {
    std::cout << "Potion " << name << " has been consumed." << std::endl;
}

char Potion::getSymbol() const {
    return symbol;
}

int Potion::getHealth() const {
    return health;
}