#include "Monster1.h"
#include <iostream>

Monster::Monster(const std::string& monsterName, int monsterHealth, int monsterDamage)
    : health(monsterHealth), damage(monsterDamage) {
    name = monsterName;
    symbol = 'M';
}

Monster::~Monster() {
    std::cout << "Monster " << name << " has been defeated." << std::endl;
}

int Monster::getHealth() const {
    return health;
}

int Monster::getDamage() const {
    return damage;
}
