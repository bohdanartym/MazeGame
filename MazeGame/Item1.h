#pragma once
#include <string>
#include "../Project1/ElementType.h"

class Item {
protected:
    std::string name;
    char symbol;

public:
    virtual ~Item() {}
    std::string getName() const;
    char getSymbol() const;
    virtual ElementType getType() = 0;
};
