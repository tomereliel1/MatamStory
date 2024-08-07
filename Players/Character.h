#pragma once
#include <string>
using std::string;
class Character{

public:
    Character() =default;
    virtual string getType() const;
};