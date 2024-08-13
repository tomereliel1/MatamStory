#include "SolarEclipse.h"
#include "Utilities.h"
#include <string>
using std::string;

const string str = "SolarEclipse";

SolarEclipse::SolarEclipse() : SpecialEvent(str) {}

string SolarEclipse::playEvent( Player &player) {
    int forceEffect = player.getJob()->applySolarEclipse(player);
    return getSolarEclipseMessage(player, forceEffect);
}

