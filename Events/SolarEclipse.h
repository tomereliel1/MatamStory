#pragma once
#include "SpecialEvent.h"
#include <string>
using std::string;
class SolarEclipse :public SpecialEvent{

public:
    explicit SolarEclipse(string & type);
    void playEvent( Player& player) const override;
};

