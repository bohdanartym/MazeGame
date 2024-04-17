#pragma once
#include <iostream>
#include "Armor1.h"
using namespace std;

Armor::Armor(const string& armorName, char armorSymbol, int armorValue) {
    name = armorName;
    symbol = armorSymbol;
    armor = armorValue;
};
    
    

Armor::~Armor() {
    cout << "Armor " << name << " has been equipped." << std::endl;
}



int Armor::getArmor() const {
    return armor;
}

string Armor::getType() {
    return "Armor";
}