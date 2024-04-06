#pragma once
#include <iostream>
#include <string>
#include "Hero1.h"
#include "HealthBar1.h"

class Monster {
private:
    std::string name;
    int health;
    int currentHealth;
    int damage;
    int armor;
    HealthBar healthBar;

public:
    Monster(const std::string& monsterName, int baseHealth, int baseDamage, int baseArmor);
    ~Monster();

    void takeDamage(int damageTaken);
    void regenerate();
    std::string getName() const;
    void setArmor(int newArmor);
    void checkDeath() const;
    void giveDamage(Hero& target);
};
