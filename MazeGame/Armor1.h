#pragma once
#include <string>
#include "Item1.h"
#include "../Project1/ElementType.h"

class Armor : public Item {
private:
    int armor;

public:
    Armor(const std::string& armorName, char armorSymbol, int armorValue);
    ~Armor();
    int getArmor() const;
    ElementType getType() override {
        return ElementType::Armor;
    };
};

