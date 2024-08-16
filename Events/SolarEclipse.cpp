#include "SolarEclipse.h"
#include "Utilities.h"

using std::string;

const string SOLAR_ECLIPSE_TYPE = "SolarEclipse";

SolarEclipse::SolarEclipse() : SpecialEvent(SOLAR_ECLIPSE_TYPE) {}

string SolarEclipse::playEvent(Player &player) {
    int forceEffect = player.getJob()->applySolarEclipse(player);
    return getSolarEclipseMessage(player, forceEffect);
}

