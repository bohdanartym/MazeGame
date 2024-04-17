#pragma once
using namespace std;

class Item {
protected:
    string name;
    char symbol;


public:
    string getName() const;
    char getSymbol() const;

    virtual string getType() = 0;


};
