#include "Player.h"

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