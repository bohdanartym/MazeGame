#pragma once

class HealthBar {
private:
    int length;
    int maxLength;

public:
    HealthBar(int maxLen);
    void update(int currentHealth, int maxHealth, int damageTaken);
    void display() const;
};
