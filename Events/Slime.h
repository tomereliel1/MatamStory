#pragma once
#include "Encounter.h"
#include <string>
using std::string;
class Slime :public Encounter{
public:
    explicit Slime(string & type);
};