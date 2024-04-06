#pragma once
#include "Labirynth1.h"
#include "Hero1.h"

class Game {
private:
    Labirynth& labirynth;
    Hero& hero;

public:
    Game(Labirynth& lab, Hero& h);

    void move(char direction);
    void generateMatrix();
    bool isPathPossible();
};
