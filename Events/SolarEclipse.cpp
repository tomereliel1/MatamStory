#include "SolarEclipse.h"
#include <string>
using std::string;


SolarEclipse::SolarEclipse(string &type) : SpecialEvent(type) {}

void SolarEclipse::playEvent( Player &player) const {
    player.getJob()->applySolarEclipse(player);
}

