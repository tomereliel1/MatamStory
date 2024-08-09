#include "SolarEclipse.h"
#include <string>
using std::string;


SolarEclipse::SolarEclipse(string &type) : SpecialEvent(type) {}

void SolarEclipse::playEvent( Player &player) const {

    std::shared_ptr<Job> currentJob = player.getJob();

    currentJob->applySolarEclipe(player);
}
