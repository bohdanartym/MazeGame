#include "Armor1.h"
#include <iostream>

Armor::Armor(const std::string& armorName, char armorSymbol, int armorValue) {
    name = armorName;
    symbol = armorSymbol;
    armor = armorValue;
}

Armor::~Armor() {
    std::cout << "Armor " << name << " has been equipped." << std::endl;
}

int Armor::getArmor() const {
    return armor;
}
