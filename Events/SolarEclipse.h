#pragma once
#include "SpecialEvent.h"
#include <string>
using std::string;
class SolarEclipse :public SpecialEvent{

public:
    SolarEclipse();
    string playEvent( Player& player) override;
};

