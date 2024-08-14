#include "Job.h"
#include "Player.h"

Job::Job(const string &type, bool closeRanged) : m_type(type), m_closeRanged(closeRanged) {}

int Job::getMaxHP() const {
    return 100;
}

int Job::getCoins() const {
    return 10;
}

int Job::getCombatPower(int force, int level) const {
    return force + level;
}

string Job::getType() const {
    return m_type;
}

int Job::applySolarEclipse(Player &player) {
    int currentForce = player.getForce();
    currentForce--;
    player.setForce(currentForce);
    return -1;
}

void Job::playerWon(Player &player, int loot) const {
    int currentLevel = player.getLevel();
    int currentCoins = player.getCoins();
    if (m_closeRanged) {
        int currentHP = player.getHealthPoints();
        currentHP -= 10;
        if (currentHP < 0) {
            currentHP = 0;
        }
        player.setHP(currentHP);
    }
    currentLevel++;
    currentCoins += loot;
    player.setLevel(currentLevel);
    player.setCoins(currentCoins);
}


void Job::playerLost(Player &player, int damage) {
    int currentHP = player.getHealthPoints();
    if (currentHP - damage < 0) {
        currentHP = 0;
    }
    else {
        currentHP -= damage;
    }
    player.setHP(currentHP);
}