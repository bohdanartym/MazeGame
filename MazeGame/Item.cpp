#include "Item1.h"

Item::Item() {}

void Item::addItem(const Armor& armor) {
    armors.push_back(armor);
}

void Item::addItem(const Potion& potion) {
    potions.push_back(potion);
}

const std::vector<Armor>& Item::getArmors() const {
    return armors;
}

const std::vector<Potion>& Item::getPotions() const {
    return potions;
}