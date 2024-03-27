#include <iostream> 
#include "Hero.cpp"
#include "Monster.cpp"
#include "Trap.cpp"
#include "Item.cpp"
using namespace std;

struct GameElement {
    variant<std::reference_wrapper<Hero>, std::reference_wrapper<Monster>, std::reference_wrapper<Trap>, std::reference_wrapper<Item>> element;

    GameElement(Hero& hero) : element(std::ref(hero)) {}
    GameElement(Monster& monster) : element(std::ref(monster)) {}
    GameElement(Trap& trap) : element(std::ref(trap)) {}
    GameElement(Item& item) : element(std::ref(item)) {}
};