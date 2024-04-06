#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include "GameElement1.h"

enum class ElementType {
    Wall,
    Passage,
    Potion,
    Trap,
    Monster,
    Hero
};

class Labirynth {
private:
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<GameElement>> gameElements;

public:
    Labirynth(const std::vector<std::vector<int>>& labyrinthMatrix);

    void initializeGameElements();
    void displayLabirynth() const;
    ElementType getElement(int row, int col) const;
    int getSize() const;
    int getRowSize(int row) const;
};
