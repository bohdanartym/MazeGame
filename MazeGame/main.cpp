#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "Labirynth1.h"
#include "GameElement1.h"
#include "Game1.h"
#include "Hero1.h"
#include "Monster1.h"
#include "Trap1.h"
#include "Potion1.h"
#include "Armor1.h"

using namespace std;

const int N = 20; // Size of the maze

void generateMatrix(Labirynth& lab) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < lab.getSize(); ++i) {
        for (int j = 0; j < lab.getRowSize(i); ++j) {
            int randValue = distribution(generator);
            /*if (randValue >= 63) {
                lab.setElement(i, j, GameElement(nullptr, nullptr, nullptr, nullptr));
            }*/
            //else {
                // Randomly add different elements such as walls, monsters, traps, potions, armor, etc.
                if (randValue < 30) {
                    lab.setElement(i, j, GameElement(new Hero("Some Hero", 100, 10))); // Hero
                }
                else if (randValue < 50) {
                    lab.setElement(i, j, GameElement(new Monster("Monster", 100, 20))); // Monster
                }
                else if (randValue < 70) {
                    lab.setElement(i, j, GameElement(new Trap("Trap", 'T', 10))); // Trap
                }
                else if (randValue < 85) {
                    lab.setElement(i, j, GameElement(new Potion("Potion", 'P', 10))); // Potion
                }
            //}
        }
    }
}


int main() {
    Labirynth lab(N, N);
    generateMatrix(lab);
    lab.displayLabirynth();

    Hero hero("Hero", 100, 20);
    Game game(lab, hero);

    char direction;
    while (true) {
        cout << "Enter direction (W/A/S/D): ";
        cin >> direction;

        game.move(direction);
        lab.displayLabirynth();
    }

    return 0;
}
