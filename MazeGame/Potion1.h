#pragma once
#include <string>

class Potion {
private:
    std::string name;
    char symbol;
    int health;

public:
    Potion(const std::string& potionName, char potionSymbol, int healthGain);
    ~Potion();
    char getSymbol() const;
    int getHealth() const;
};