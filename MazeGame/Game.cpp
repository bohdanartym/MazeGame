#include "Game1.h"
#include <iostream>
#include <queue>
#include <limits>

using namespace std;

Game::Game(Labirynth& lab, Hero& h) : labirynth(lab), hero(h) {}

void Game::move(char direction) {
    pair<int, int> heroPos = hero.getPosition();

    int heroRow = heroPos.first;
    int heroCol = heroPos.second;

    switch (direction) {
    case 'W':
        if (heroRow > 0 && labirynth.getElement(heroRow - 1, heroCol).getType() != ElementType::Wall) {
            labirynth.moveElement(heroRow, heroCol, heroRow - 1, heroCol);
            hero.setPosition(heroRow - 1, heroCol);
        }
        break;
    case 'A':
        if (heroCol > 0 && labirynth.getElement(heroRow, heroCol - 1).getType() != ElementType::Wall) {
            labirynth.moveElement(heroRow, heroCol, heroRow, heroCol - 1);
            hero.setPosition(heroRow, heroCol - 1);
        }
        break;
    case 'S':
        if (heroRow < labirynth.getSize() - 1 && labirynth.getElement(heroRow + 1, heroCol).getType() != ElementType::Wall) {
            labirynth.moveElement(heroRow, heroCol, heroRow + 1, heroCol);
            hero.setPosition(heroRow + 1, heroCol);
        }
        break;
    case 'D':
        if (heroCol < labirynth.getRowSize(heroRow) - 1 && labirynth.getElement(heroRow, heroCol + 1).getType() != ElementType::Wall) {
            labirynth.moveElement(heroRow, heroCol, heroRow, heroCol + 1);
            hero.setPosition(heroRow, heroCol + 1);
        }
        break;
    default:
        std::cout << "Invalid direction. Use W, A, S, or D." << std::endl;
    }
}

bool Game::isPathPossible() {
    int size = labirynth.getSize();
    pair<int, int> startPos = hero.getPosition();
    vector<vector<int>> distance(size, vector<int>(size, numeric_limits<int>::max()));
    distance[startPos.first][startPos.second] = 0;

    auto compare = [](const pair<int, pair<int, int>>& lhs, const pair<int, pair<int, int>>& rhs) {
        return lhs.first > rhs.first;
        };

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(compare)> pq(compare);
    pq.push({ 0, startPos });

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentRow = pq.top().second.first;
        int currentCol = pq.top().second.second;
        pq.pop();

        int dr[] = { -1, 1, 0, 0 };
        int dc[] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; ++i) {
            int newRow = currentRow + dr[i];
            int newCol = currentCol + dc[i];

            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                int edgeWeight = labirynth.getElement(newRow, newCol).getWeight();
                if (currentDistance + edgeWeight < distance[newRow][newCol]) {
                    distance[newRow][newCol] = currentDistance + edgeWeight;
                    pq.push({ distance[newRow][newCol], {newRow, newCol} });
                }
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        if (distance[size - 1][i] != numeric_limits<int>::max()) {
            return true;
        }
    }

    return false;
}
