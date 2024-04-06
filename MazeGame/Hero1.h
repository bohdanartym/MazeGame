#pragma once
#include "Armor1.h"
#include "HealthBar1.h"

class Hero {
private:
    std::string name;
    int health;
    int currentHealth;
    int damage;
    std::vector<Item> items;
    int armor;
    int experience;
    int level;
    HealthBar healthBar;

public:
    Hero(const std::string& heroName, int baseHealth, int baseDamage);
    ~Hero();

    void gainExperience(int exp);
    void giveDamage(Hero& enemy);
    void displayHealthBar() const;
    void takeDamage(int damageTaken);
    void heal(int amount);
    void levelUp();
    void equipItem(const Item& newItem);
    int calculateTotalDamageBoost() const;
    void equipArmor(Armor& newArmor);
    int calculateTotalArmorBoost() const;
    void checkDeath() const;
    std::string getName();
};