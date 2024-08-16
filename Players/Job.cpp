#include "Job.h"
#include "Player.h"

const int DEFAULT_HP = 100;
const int DEFAULT_COINS = 10;
const int DEFAULT_SOLAR_ECLIPSE_EFFECT = -1;
const int CLOSE_RANGED_ADDITIONAL_DAMAGE = 10;

Job::Job(const string &type, bool closeRanged) : m_type(type), m_closeRanged(closeRanged) {}

int Job::getMaxHP() const {
    return DEFAULT_HP;
}

int Job::getCoins() const {
    return DEFAULT_COINS;
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
    return DEFAULT_SOLAR_ECLIPSE_EFFECT;
}

void Job::playerWon(Player &player, int loot) const {
    int currentLevel = player.getLevel();
    int currentCoins = player.getCoins();
    if (m_closeRanged) {
        int currentHP = player.getHealthPoints();
        currentHP -= CLOSE_RANGED_ADDITIONAL_DAMAGE;
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