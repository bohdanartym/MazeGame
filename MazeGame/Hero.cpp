#pragma once
#include "Hero1.h"
#include <string>
#include <iostream>
using namespace std;

Hero::Hero(const std::string& heroName, int baseHealth, int baseDamage)
    : name(heroName), health(baseHealth), currentHealth(baseHealth),
    damage(baseDamage), armor(0), experience(0), level(1), healthBar(baseHealth) {}

Hero::~Hero() {
    cout << "Hero " << name << " has been defeated!" << std::endl;
}

void Hero::gainExperience(int exp) {
    experience += exp;
    cout << name << " gained " << exp << " experience points." << std::endl;
    levelUp();
}

void Hero::giveDamage(Hero& enemy) {
    int totalDamage = damage + calculateTotalDamageBoost();
    enemy.takeDamage(totalDamage);
    std::cout << name << " dealt " << totalDamage << " damage to " << enemy.name << "." << std::endl;
}

void Hero::displayHealthBar() const {
    int healthBarLength = 100;
    int remainingHealthBar = static_cast<int>((static_cast<double>(currentHealth) / health) * healthBarLength);

    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    for (int i = 0; i < healthBarLength - remainingHealthBar; ++i) {
        std::cout << "#";
    }

    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    for (int i = 0; i < remainingHealthBar; ++i) {
        std::cout << "#";
    }

    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Hero::takeDamage(int damageTaken) {
    int totalArmor = calculateTotalArmorBoost();
    int damageReceived = std::max(0, damageTaken - totalArmor);
    currentHealth -= damageReceived;
    displayHealthBar();
    checkDeath();
}

void Hero::heal(int amount) {
    currentHealth = std::min(health, currentHealth + amount);
    healthBar.update(currentHealth, health, 0);
    std::cout << name << " healed for " << amount << " health points." << std::endl;
}

void Hero::levelUp() {
    int experienceToLevelUp = level * 100;
    if (experience >= experienceToLevelUp) {
        ++level;
        health += 10;
        damage += 5;
        std::cout << name << " leveled up to level " << level << "!" << std::endl;
        experience -= experienceToLevelUp;
        levelUp();
    }
}

void Hero::equipItem(const Item& newItem) {
    items.push_back(newItem);
    std::cout << name << " equipped " << newItem.name << "." << std::endl;
}

int Hero::calculateTotalDamageBoost() const {
    int totalBoost = 0;
    for (const auto& item : items) {
        totalBoost += item.damageBoost;
    }
    return totalBoost;
}
void Hero::equipArmor(Armor& newArmor) {
    armor += newArmor.giveArmor();
}
int Hero::calculateTotalArmorBoost() const {
    int totalBoost = 0;
    for (const auto& item : items) {
        totalBoost += item.armorBoost;
    }
    return totalBoost + armor;
}

void Hero::checkDeath() const {
    if (currentHealth <= 0) {
        std::cout << name << " has been defeated!" << std::endl;
    }
}
string Hero::getName() {
    return name;
}
