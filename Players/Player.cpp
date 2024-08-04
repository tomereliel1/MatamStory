#include "Player.h"

string Player::getDescription() const {
    string description = m_name + ", " + m_job + " with " + m_character.getType() + " character (level "+
            std::to_string(m_level) + ", force " + std::to_string(m_force);
    return description;
}

string Player::getName() const {
    return m_name;
}

int Player::getLevel() const {
    return m_level;
}

int Player::getForce() const {
    return m_force;
}

int Player::getHealthPoints() const {
    return m_currentHP;
}

int Player::getCoins() const {
    return m_coins;
}