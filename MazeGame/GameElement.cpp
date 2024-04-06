#pragma once
#include <iostream> 
#include "Hero.cpp"
#include "Monster.cpp"
#include "Trap.cpp"
#include "Item.cpp"
using namespace std;

struct GameElement {
    Hero* _hero;
    Monster* monster;
    Trap* trap;
    Item* item;

    //variant<std::reference_wrapper<Hero>, std::reference_wrapper<Monster>, std::reference_wrapper<Trap>, std::reference_wrapper<Item>> element;

    GameElement(Hero* hero): _hero(hero), monster(nullptr), trap(nullptr), item(nullptr) {}
    GameElement(Monster* monster) : _hero(nullptr), monster(monster), trap(nullptr), item(nullptr) {}
    GameElement(Trap* trap) : _hero(nullptr), monster(nullptr), trap(trap), item(nullptr) {}
    GameElement(Item* item) : _hero(nullptr), monster(nullptr), trap(nullptr), item(item) {}
};