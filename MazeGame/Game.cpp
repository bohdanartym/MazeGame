#include <iostream> 
#include "Hero.cpp"
#include "Labirynth.cpp"
#include "GameElement.cpp"


class Game {
private:
    Labirynth& labirynth;
    Hero& hero;

public:
    Game(Labirynth& lab, Hero& h) : labirynth(lab), hero(h) {}

    // Method to handle the movement of the hero 
    void move(char direction) {
        int heroRow = -1;
        int heroCol = -1;

        // Find the current position of the hero in the labyrinth 
        for (int i = 0; i < labirynth.getSize(); ++i) {
            for (int j = 0; j < labirynth.getRowSize(i); ++j) {
                if (labirynth.getElement(i, j).getType() == ElementType::Hero) {
                    heroRow = i;
                    heroCol = j;
                    break;
                }
            }
            if (heroRow != -1) {
                break;
            }
        }
        void handleMovement() {
            char direction;
            std::cout << "Enter your move (W, A, S, D): ";
            std::cin >> direction;

            switch (direction) {
            case 'W':
            case 'w':
                moveHero(-1, 0); // Move up 
                break;
            case 'A':
            case 'a':
                moveHero(0, -1); // Move left 
                break;
            case 'S':
            case 's':
                moveHero(1, 0); // Move down 
                break;
            case 'D':
            case 'd':
                moveHero(0, 1); // Move right 
                break;
            default:
                std::cout << "Invalid direction. Use W, A, S, or D." << std::endl;
            }
        }
        // Update the position based on the movement direction 
        switch (direction) {
        case 'W':
            if (heroRow > 0 && labirynth.getElement(heroRow - 1, heroCol).getType() != ElementType::Wall) {
                std::swap(labirynth.getElement(heroRow, heroCol), labirynth.getElement(heroRow - 1, heroCol));
            }
            break;
        case 'A':
            if (heroCol > 0 && labirynth.getElement(heroRow, heroCol - 1).getType() != ElementType::Wall) {
                std::swap(labirynth.getElement(heroRow, heroCol), labirynth.getElement(heroRow, heroCol - 1));
            }
            break;
        case 'S':
            if (heroRow < labirynth.getSize() - 1 && labirynth.getElement(heroRow + 1, heroCol).getType() != ElementType::Wall) {
                std::swap(labirynth.getElement(heroRow, heroCol), labirynth.getElement(heroRow + 1, heroCol));
            }
            break;
        case 'D':
            if (heroCol < labirynth.getRowSize(heroRow) - 1 && labirynth.getElement(heroRow, heroCol + 1).getType() != ElementType::Wall) {
                std::swap(labirynth.getElement(heroRow, heroCol), labirynth.getElement(heroRow, heroCol + 1));
            }
            break;
        default:
            std::cout << "Invalid direction. Use W, A, S, or D." << std::endl;
        }
    }

    // Method to generate the maze 
    void generateMatrix() {
        srand(static_cast<unsigned>(time(nullptr)));

        for (int i = 0; i < labirynth.getSize(); ++i) {
            for (int j = 0; j < labirynth.getRowSize(i); ++j) {
                int randValue = rand() % 5;  // Random value from 0 to 4 

                if (randValue == 0) {
                    // Wall 
                    labirynth.getElement(i, j) = GameElement();
                }
                else if (randValue == 1) {
                    // Passageway 
                    labirynth.getElement(i, j) = GameElement();
                }
                else if (randValue == 2) {
                    // Potion 
                    Item potion("Potion", 0, 0, 5);  // Assuming Item class has been defined 
                    labirynth.getElement(i, j) = GameElement(potion);
                }
                else if (randValue == 3) {
                    // Trap 
                    Trap trap("Trap", 10);  // Assuming Trap class has been defined 
                    labirynth.getElement(i, j) = GameElement(trap);
                }
                else if (rand
                    Value == 4) {
                    // Monster 
                    Monster monster("Monster", 30, 15, 5);  // Assuming Monster class has been defined 
                    labirynth.getElement(i, j) = GameElement(monster);
                }
            }
        }

        // Place the hero at a random position 
        int heroRow = rand() % labirynth.getSize();
        int heroCol = rand() % labirynth.getRowSize(heroRow);
        labirynth.getElement(heroRow, heroCol) = GameElement(hero);
    }

    bool isPathPossible() {
        // Dijkstra algorithm implementation 
        int size = labirynth.getSize();
        int startRow = hero.getPosition().first;
        int startCol = hero.getPosition().second;

        std::vector<std::vector<int>> distance(size, std::vector<int>(size, std::numeric_limits<int>::max()));
        distance[startRow][startCol] = 0;

        auto compare = [](const std::pair<int, std::pair<int, int>>& lhs, const std::pair<int, std::pair<int, int>>& rhs) {
            return lhs.first > rhs.first;
            };

        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, decltype(compare)> pq(compare);
        pq.push({ 0, {startRow, startCol} });

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int currentRow = pq.top().second.first;
            int currentCol = pq.top().second.second;
            pq.pop();

            // Check neighbors (up, down, left, right) 
            int dr[] = { -1, 1, 0, 0 };
            int dc[] = { 0, 0, -1, 1 };

            for (int i = 0; i < 4; ++i) {
                int newRow = currentRow + dr[i];
                int newCol = currentCol + dc[i];

                if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                    int edgeWeight = labirynth.getElement(newRow, newCol).getWeight();  // Assuming GameElement has getWeight() method 
                    if (currentDistance + edgeWeight < distance[newRow][newCol]) {
                        distance[newRow][newCol] = currentDistance + edgeWeight;
                        pq.push({ distance[newRow][newCol], {newRow, newCol} });
                    }
                }
            }
        }

        // Check if there is a path to the exit (assuming exit is at the last row) 
        for (int i = 0; i < size; ++i) {
            if (distance[size - 1][i] != std::numeric_limits<int>::max()) {
                return true;
            }
        }
        _asm {
        }


        return false;
    }
};