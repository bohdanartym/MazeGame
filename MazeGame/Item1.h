#pragma once
#include <vector>
#include "Armor1.h"
#include "Potion1.h"
using namespace std;

class Item {
private:
    vector<Armor> armors;
    vector<Potion> potions;

public:
    Item();
    void addItem(const Armor& armor);
    void addItem(const Potion& potion);
    const std::vector<Armor>& getArmors() const;
    const std::vector<Potion>& getPotions() const;
};
