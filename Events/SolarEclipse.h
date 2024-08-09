#include "SpecialEvent.h"
#pragma once
#include <string>
using std::string;

class SolarEclipse : SpecialEvent {

public:

    void playEvent( Player& player) const override;

    explicit SolarEclipse(string & type);
};