#include <iostream> 
#include "Hero.cpp"
class Trap {
private:
    std::string name;
    char symbol;
    int damage;

public:

    Trap(const std::string& trapName, char trapSymbol, int trapDamage)
        : name(trapName), symbol(trapSymbol), damage(trapDamage) {}

    ~Trap() {
        std::cout << "Trap " << name << " has been triggered." << std::endl;
    }

    char getSymbol() const {
        return symbol;
    }

    void getDamageFromTrap(Hero& target) {
        target.takeDamage(damage);
        std::cout << target.getName() << " triggered " << name << " and took " << damage << " damage." << std::endl;
    }
};
