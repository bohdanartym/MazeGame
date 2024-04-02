#include <iostream> 
#include "Hero.cpp"

class Armor {
private:
    std::string name;
    char symbol;
    int armor;

public:
    Armor(const std::string& armorName, char armorSymbol, int armorValue)
        : name(armorName), symbol(armorSymbol), armor(armorValue) {}

    ~Armor() {
        std::cout << "Armor " << name << " has been equipped." << std::endl;
    }

    char getSymbol() const {
        return symbol;
    }

    void giveArmor(Hero& target) {
        target.equipArmor(*this);
        std::cout << target.getName() << " gained " << armor << " armor from " << name << "." << std::endl;
    }
};
