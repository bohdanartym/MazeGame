#pragma once
#include <string>
#include "Item1.h"


class Armor : Item {
private:
    
    int armor;

public:
    Armor(const std::string& armorName, char armorSymbol, int armorValue);
    ~Armor();
    int getArmor() const;
    string getType();


};
