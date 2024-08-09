#pragma once
#include "Encounter.h"
#include <string>
#include <memory>
using std::string;
class Barlog :public Encounter{
public:
    explicit Barlog(string & type);
};

