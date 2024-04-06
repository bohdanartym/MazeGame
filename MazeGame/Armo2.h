#include <iostream> 
#include "Hero.cpp"

#ifndef ARMO_2
#define ARMO_2
class Armo2
{
private:
    std::string name;
    char symbol;
    int armor;

public:
    Armo2(const std::string& armorName, char armorSymbol, int armorValue);
        
    Armo2();

    ~Armo2();

    char getSymbol() const;

    void giveArmor(Hero& target);
};

#endif
