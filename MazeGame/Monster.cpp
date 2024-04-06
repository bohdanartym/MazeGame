#include "Monster1.h"

Monster::Monster(const std::string& monsterName, int baseHealth, int baseDamage, int baseArmor)
    : name(monsterName), health(baseHealth), currentHealth(baseHealth),
    damage(baseDamage), armor(baseArmor), healthBar(baseHealth) {}

Monster::~Monster() {
    std::cout << "Monster " << name << " has been defeated!" << std::endl;
}

void Monster::takeDamage(int damageTaken) {
    int damageReceived = std::max(0, damageTaken - armor);
    currentHealth -= damageReceived;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "Monster " << name << " Health: ";
    for (int i = 0; i < currentHealth; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    checkDeath();
}

void Monster::regenerate() {
    int regenerationAmount = 10;
    currentHealth = std::min(health, currentHealth + regenerationAmount);
    healthBar.update(currentHealth, health, 0);
    std::cout << name << " regenerates for " << regenerationAmount << " health points." << std::endl;
}

std::string Monster::getName() const {
    return name;
}

void Monster::setArmor(int newArmor) {
    armor = newArmor;
    std::cout << name << "'s armor has been updated to " << armor << "." << std::endl;
}

void Monster::checkDeath() const {
    if (currentHealth <= 0) {
        std::cout << name << " has been defeated!" << std::endl;
    }
}

void Monster::giveDamage(Hero& target) {
    int totalDamage = damage;
    target.takeDamage(totalDamage);
}