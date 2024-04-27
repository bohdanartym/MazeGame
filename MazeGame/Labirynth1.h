#pragma once

#include <vector>
#include "GameElement1.h"

class Labirynth {
private:
    std::vector<std::vector<int>> matrix; // This is the matrix storing the layout of the labyrinth
    std::vector<std::vector<GameElement>> gameElements; // This matrix stores the game elements at each position

public:
    Labirynth(int n, int m);
    Labirynth(const std::vector<std::vector<int>>& labyrinthMatrix);

    void initializeGameElements();

    void displayLabirynth() const;

    GameElement getElement(int row, int col) const;
    void setElement(int row, int col, const GameElement& element);

    int getSize() const;
    int getRowSize(int row) const;

    void moveElement(int fromRow, int fromCol, int toRow, int toCol);
};
