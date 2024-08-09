#include "Job.h"
Job::Job(string type): m_type(type){}

int Job::getMaxHP() const{
    return 100;
}

int Job::getCoins() const{
    return 10;
}

int Job::getCombatPower(int force, int level) const {
    return force + level;
}

string Job::getType() const {
    return m_type;
}

void Job::applySolarEclipe(Player &player) {
    int currentForce=player.getForce();
    currentForce--;
    player.setForce(currentForce);
}
