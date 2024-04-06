#include "HealthBar1.h"
#include <iostream>
#include <algorithm>

HealthBar::HealthBar(int maxLen) : length(maxLen), maxLength(maxLen) {}

void HealthBar::update(int currentHealth, int maxHealth, int damageTaken) {
    length = static_cast<int>((static_cast<double>(currentHealth) / maxHealth) * maxLength);
    length = std::max(0, length - damageTaken);
}

void HealthBar::display() const {
    for (int i = 0; i < length; ++i) {
        std::cout << "#";
    }
}