#pragma once
#include <iostream>
#include <functional>
#include "Hero.cpp"
#include "Monster1.h"
#include "Trap.cpp"
#include "Item1.h"
using namespace std;
enum class ElementType {
    Wall,
    Passage,
    Potion,
    Trap,
    Monster,
    Hero
};
struct GameElement {
    Hero* _hero;
    Monster* monster;
    Trap* trap;
    Item* item;

    GameElement(Hero* hero) : _hero(hero), monster(nullptr), trap(nullptr), item(nullptr) {}
    GameElement(Monster* monster) : _hero(nullptr), monster(monster), trap(nullptr), item(nullptr) {}
    GameElement(Trap* trap) : _hero(nullptr), monster(nullptr), trap(trap), item(nullptr) {}
    GameElement(Item* item) : _hero(nullptr), monster(nullptr), trap(nullptr), item(item) {}

    // Add a method to get the type of the element
    ElementType getType() const {
        if (_hero != nullptr) return ElementType::Hero;
        if (monster != nullptr) return ElementType::Monster;
        if (trap != nullptr) return ElementType::Trap;
        if (item != nullptr) return ElementType::Potion; // Assuming item represents a potion
        return ElementType::Wall; // Default case
    }
};

