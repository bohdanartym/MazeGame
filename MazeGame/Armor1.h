#pragma once
#include <string>

class Armor {
private:
    std::string name;
    char symbol;
    int armor;

public:
    Armor(const std::string& armorName, char armorSymbol, int armorValue);
    ~Armor();
    char getSymbol() const;
    int getArmor() const;
};
