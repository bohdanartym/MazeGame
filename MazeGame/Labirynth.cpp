#pragma once
#include "Labirynth1.h"
#include "Hero1.h"
#include "GameElement1.h"
#include "Trap1.h"
#include <iostream>
    using namespace std;

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
                    rowElements.emplace_back(new Item());
                    break;
                case 3:  // Trap 
                    // Create a Trap object with parameters and pass it to GameElement constructor
                    rowElements.emplace_back(new Trap("Some Trap", 'T', 10)); // Assuming Trap constructor takes name, symbol, and damage as parameters
                    break;
                case 4:  // Monster 
                    // Create a Monster object with parameters and pass it to GameElement constructor
                    rowElements.emplace_back(new Monster("Some Monster", 100, 20, 5)); // Assuming Monster constructor takes name, health, damage, and armor as parameters
                    break;
                case '@':  // Hero 
                    // Create a Hero object with parameters and pass it to GameElement constructor
                    rowElements.emplace_back(new Hero("Some Hero", 100, 20)); // Assuming Hero constructor takes name, health, and damage as parameters
                    break;
                default:
                    // Initialize a wall or other default element 
                    rowElements.emplace_back(nullptr);
                    break;
                }
            }
            gameElements.push_back(rowElements);
        }
    }

    void Labirynth::displayLabirynth() const {
        for (const auto& row : matrix) {
            for (int cell : row) {
                switch (cell) {
                case 0:  // Wall 
                    std::cout << "| ";
                    break;
                case 1:  // Passage 
                    std::cout << "  ";
                    break;
                case 2:  // Potion 
                    std::cout << "P ";
                    break;
                case 3:  // Trap 
                    std::cout << "T ";
                    break;
                case 4:  // Monster 
                    std::cout << "M ";
                    break;
                case '@':  // Hero 
                    std::cout << "@ ";
                    break;
                default:
                    // Handle other elements if needed 
                    std::cout << "? ";
                    break;
                }
            }
            std::cout << std::endl;
        }
    }

    ElementType Labirynth::getElement(int row, int col) const {
        // Check if the provided indices are within the bounds of the matrix
        if (row < 0 || row >= gameElements.size() || col < 0 || col >= gameElements[row].size()) {
            // Handle out-of-bounds access
            return ElementType::Wall; // Return a default element type (e.g., Wall)
        }

        // Return the type of the element at the specified position
        return gameElements[row][col].getType();
    }

    int Labirynth::getSize() const {
        return matrix.size();
    }

    int Labirynth::getRowSize(int row) const {
        return matrix[row].size();
    }
};
