#include "Hero1.h"
#include <iostream>

Hero::Hero(const std::string& heroName, int heroHealth, int heroDamage)
    : name(heroName), health(heroHealth), damage(heroDamage), symbol('H') {}

Hero::~Hero() {
    std::cout << "Hero " << name << " has been defeated." << std::endl;
}

int Hero::getHealth() const {
    return health;
}

int Hero::getDamage() const {
    return damage;
}

std::pair<int, int> Hero::getPosition() const {
    return position;
}

void Hero::setPosition(int row, int col) {
    position = { row, col };
}
