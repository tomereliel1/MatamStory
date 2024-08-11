#include "Job.h"
#include "Player.h"
Job::Job(const string& type): m_type(type){}

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

void Job::applySolarEclipse(Player &player) {
    int currentForce= player.getForce();
    currentForce--;
    player.setForce(currentForce);
}

void Job::playerWon(Player &player) const {
    int currentLevel = player.getLevel();
    currentLevel++;
    player.setLevel(currentLevel);
}