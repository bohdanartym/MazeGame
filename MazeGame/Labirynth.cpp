#include "Labirynth1.h"
#include <iostream>
#include "GameElement.cpp"
#include "GameElement1.h"
#include <random>
#include <chrono>
using namespace std;

Labirynth::Labirynth(int n, int m) {
    for (int i = 0; i < n; i++) {
        matrix.push_back(std::vector<int>(m, 0));
    }
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (distribution(generator) >= 63) {
                matrix[i][j] = 1;
            }
            else matrix[i][j] = 0;
        }
    }
    initializeGameElements();
}

Labirynth::Labirynth(const std::vector<std::vector<int>>& labyrinthMatrix) : matrix(labyrinthMatrix) {
    initializeGameElements();
}

void Labirynth::initializeGameElements() {
    for (size_t i = 0; i < matrix.size(); ++i) {
        std::vector<GameElement> rowElements;
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            switch (matrix[i][j]) {
            case 2:  // Potion 
                // Create an Item object and pass it to GameElement constructor
                rowElements.emplace_back(new Potion("Some Potion", 'P', 10)); // Assuming Potion constructor takes name, symbol, and health as parameters
                break;
            case 3:  // Trap 
                // Create a Trap object with parameters and pass it to GameElement constructor
                rowElements.emplace_back(new Trap("Some Trap", 'T', 10)); // Assuming Trap constructor takes name, symbol, and damage as parameters
                break;
            case 4:  // Monster 
                // Create a Monster object with parameters and pass it to GameElement constructor
                rowElements.emplace_back(new Monster("Some Monster", 100, 10)); // Assuming Monster constructor takes name, health, and damage as parameters
                break;
            case 5:  // Hero 
                // Create a Hero object with parameters and pass it to GameElement constructor
                rowElements.emplace_back(new Hero("Some Hero", 100, 10)); // Assuming Hero constructor takes name, health, and damage as parameters
                break;
            default:
                rowElements.emplace_back(nullptr);
                break;
            }
        }
        gameElements.push_back(rowElements);
    }
}

void Labirynth::displayLabirynth() const {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            switch (matrix[i][j]) {
            case 0:
                std::cout << ".";
                break;
            case 1:
                std::cout << "#";
                break;
            case 2:
                std::cout << "P";
                break;
            case 3:
                std::cout << "T";
                break;
            case 4:
                std::cout << "M";
                break;
            case 5:
                std::cout << "H";
                break;
            }
        }
        std::cout << std::endl;
    }
}

GameElement Labirynth::getElement(int row, int col) const {
    return gameElements[row][col];
}
void Labirynth::setElement(int row, int col, const GameElement& element) {
    gameElements[row][col] = element;
}
int Labirynth::getSize() const {
    return matrix.size();
}
void Labirynth::moveElement(int fromRow, int fromCol, int toRow, int toCol) {
    // Get a copy of the element at the source position
    GameElement elementToMove = gameElements[fromRow][fromCol];

    //gameElements[fromRow][fromCol] = GameElement(nullptr, nullptr, nullptr, nullptr);

    gameElements[toRow][toCol] = elementToMove;
}
int Labirynth::getRowSize(int row) const {
    return matrix[row].size();
}
