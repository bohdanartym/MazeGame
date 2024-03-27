#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
#include <windows.h> 
#include <variant> 
#include <queue> 

class HealthBar {
private:
    int length;
    int maxLength;

public:
    HealthBar(int maxLen) : length(maxLen), maxLength(maxLen) {}

    void update(int currentHealth, int maxHealth, int damageTaken) {
        length = static_cast<int>((static_cast<double>(currentHealth) / maxHealth) * maxLength);
        length = std::max(0, length - damageTaken);
    }

    void display() const {
        for (int i = 0; i < length; ++i) {
            std::cout << "#";
        }
    }
};