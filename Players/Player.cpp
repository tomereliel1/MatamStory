#include "Player.h"
#include <string>
#include <memory>

using std::unique_ptr;
using std::string;

Player::Player(string &name, unique_ptr<Job> job, unique_ptr<Character> character) : m_name(name),
                                                                                     m_level(1),
                                                                                     m_force(5) {
    m_job = std::move(job);
    m_character = std::move(character);
    m_maxHP = m_job->getMaxHP();
    m_currentHP = m_maxHP;
    m_coins = m_job->getCoins();
}


string Player::getDescription() const {
    string description = m_name + ", " + m_job->getType() + " with " + m_character->getType()
            + " character (level " + std::to_string(m_level) + ", force " +
            std::to_string(m_force);
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