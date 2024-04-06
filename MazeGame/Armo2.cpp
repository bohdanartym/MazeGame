#include "Armo2.h"
#include <iostream> 
#include "Hero.cpp"

Armo2::Armo2(const std::string& armorName, char armorSymbol, int armorValue)
        : name(armorName), symbol(armorSymbol), armor(armorValue) {}
Armo2::Armo2() {}

Armo2::~Armo2() {
        std::cout << "Armor " << name << " has been equipped." << std::endl;
    }

    char Armo2::getSymbol() const {
        return symbol;
    }

    void Armo2::giveArmor(Hero& target) {
        target.equipArmor(*this);
        std::cout << target.getName() << " gained " << armor << " armor from " << name << "." << std::endl;
    }
