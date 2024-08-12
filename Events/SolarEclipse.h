#pragma once
#include "SpecialEvent.h"
#include <string>
using std::string;
class SolarEclipse :public SpecialEvent{

public:
    SolarEclipse();
    void playEvent( Player& player) override;
};

