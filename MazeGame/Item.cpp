#include <iostream> 

class Item {
private:
    std::vector<Armor> armors;
    std::vector<Potion> potions;

public:
    Item() {}
    void addItem(const Armor& armor) {
        armors.push_back(armor);
    }

    void addItem(const Potion& potion) {
        potions.push_back(potion);
    }
    const std::vector<Armor>& getArmors() const {
        return armors;
    }

    const std::vector<Potion>& getPotions() const {
        return potions;
    }
};
