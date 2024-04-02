#include <iostream> 
#include "Hero.cpp"

class Potion {
private:
    std::string name;
    char symbol;
    int health;

public:
    Potion(const std::string& potionName, char potionSymbol, int healthGain)
        : name(potionName), symbol(potionSymbol), health(healthGain) {}

    ~Potion() {
        std::cout << "Potion " << name << " has been consumed." << std::endl;
    }
    void giveHealth(Hero& target) {
        target.heal(health);
        std::cout << target.getName() << " gained " << health << " health points from " << name << "." << std::endl;
    }
};
