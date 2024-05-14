#pragma once
#include "Hero1.h"
#include "Monster1.h"
#include "Trap1.h"
#include "Potion1.h"

struct GameElement {
    Hero* hero;
    Monster* monster;
    Trap* trap;
    Potion* potion;
    int weight;

    GameElement(Hero& h) : hero(&h), monster(nullptr), trap(nullptr), potion(nullptr) {}
    GameElement(Monster& m) : hero(nullptr), monster(&m), trap(nullptr), potion(nullptr) {}
    GameElement(Trap& t) : hero(nullptr), monster(nullptr), trap(&t), potion(nullptr) {}
    GameElement(Potion& p) : hero(nullptr), monster(nullptr), trap(nullptr), potion(&p) {}


    ElementType getType() const {
        if (hero != nullptr) return ElementType::Hero;
        if (monster != nullptr) return ElementType::Monster;
        if (trap != nullptr) return ElementType::Trap;
        if (potion != nullptr) return ElementType::Potion;
        return ElementType::Wall; // Default case
    }
    int getWeight() const {
        return weight;
    }
};
