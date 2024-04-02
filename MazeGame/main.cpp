#include <iostream> 
#include "Hero.cpp"
#include "Labirynth.cpp"
#include "GameElement.cpp"
#include <vector>

int main() {
   
    Hero hero("Player", 100, 20);

    std::vector<std::vector<int>> mazeMatrix = {
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    Labirynth labyrinth(mazeMatrix);

    Game game(labyrinth, hero);
    game.generateMatrix();
    game.labirynth.displayLabirynth();

    char move;
    bool gameOver = false;
    while (!gameOver) {
        game.move(move);
        game.labirynth.displayLabirynth();
        gameOver = game.isPathPossible();
    }

    return 0;
}
