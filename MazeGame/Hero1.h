#ifndef HERO_H
#define HERO_H

#include <string>
#include <utility>

class Hero {
private:
    std::string name;
    int health;
    int damage;
    char symbol;
    std::pair<int, int> position;

public:
    // Constructors
    Hero(const std::string& heroName, int heroHealth, int heroDamage);
    Hero(int row, int col);

    // Destructor
    ~Hero();

    // Getter methods
    std::string getName() const;
    int getHealth() const;
    int getDamage() const;
    char getSymbol() const;
    std::pair<int, int> getPosition() const;

    // Setter method
    void setPosition(int row, int col);
};

#endif // HERO_H
