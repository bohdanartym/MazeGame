#pragma once
#include <iostream>
#include "Armor1.h"
using namespace std;

Armor::Armor(const std::string& armorName, char armorSymbol, int armorValue)
    : name(armorName), symbol(armorSymbol), armor(armorValue) {}

Armor::~Armor() {
    cout << "Armor " << name << " has been equipped." << std::endl;
}

char Armor::getSymbol() const {
    return symbol;
}

int Armor::getArmor() const {
    return armor;
}