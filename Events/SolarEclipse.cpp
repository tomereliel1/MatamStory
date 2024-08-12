#include "SolarEclipse.h"
#include <string>
using std::string;

const string str = "SolarEclipse";

SolarEclipse::SolarEclipse() : SpecialEvent(str) {}

void SolarEclipse::playEvent( Player &player) {
    player.getJob()->applySolarEclipse(player);
}

