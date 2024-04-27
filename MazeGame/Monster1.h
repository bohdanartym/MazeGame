#pragma once
#include <string>
#include "Item1.h"

class Monster : public Item {
private:
    int health;
    int damage;

public:
    Monster(const std::string& monsterName, int monsterHealth, int monsterDamage);
    ~Monster();
    int getHealth() const;
    int getDamage() const;
    ElementType getType() override {
        return ElementType::Monster;
    }
};

