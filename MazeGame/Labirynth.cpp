#include <iostream> 

class Labirynth {
private:
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<GameElement>> gameElements;

public:
    Labirynth(const std::vector<std::vector<int>>& labyrinthMatrix) : matrix(labyrinthMatrix) {
        initializeGameElements();
    }

    void initializeGameElements() {
        for (size_t i = 0; i < matrix.size(); ++i) {
            std::vector<GameElement> rowElements;
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                switch (matrix[i][j]) {
                case 1:  // Passage 
                    rowElements.emplace_back(Hero(/* Parameters for Hero initialization */));
                    break;
                case 2:  // Potion 
                    // Initialize a potion element 
                    rowElements.emplace_back(/* Parameters for Potion initialization */);
                    break;
                case 3:  // Trap 
                    // Initialize a trap element 
                    rowElements.emplace_back(/* Parameters for Trap initialization */);
                    break;
                case 4:  // Monster 
                    // Initialize a monster element 
                    rowElements.emplace_back(/* Parameters for Monster initialization */);
                    break;
                case '@':  // Hero 
                    // Initialize a hero element 
                    rowElements.emplace_back(/* Parameters for Hero initialization */);
                    break;
                default:
                    // Initialize a wall or other default element 
                    // rowElements.emplace_back(/* Parameters for default element initialization */); 
                    break;
                }
            }
            gameElements.push_back(rowElements);
        }
    }

    void displayLabirynth() const {
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

    ElementType getElement(int row, int col) const {
        return gameElements[row][col].element.type();
    }

    int getSize() const {
        return matrix.size();
    }

    int getRowSize(int row) const {
        return matrix[row].size();
    }
};
