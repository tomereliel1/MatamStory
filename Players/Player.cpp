#include "Player.h"
#include <string>
#include <memory>

using std::unique_ptr;
using std::string;

Player::Player(string name, string job, string character) : m_name(name),
                                                                                     m_level(1),
                                                                                     m_force(5) {
    m_job = m_jobFactory.create(job);
    m_character = m_characterFactory.create(character);
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

shared_ptr<Job> Player::getJob() {
    return m_job;
}

void Player::setLevel(const int &level) {
    m_level = level;
}

void Player::setForce(const int &force) {
    m_force = force;
}

void Player::setHP(const int &hp) {
    m_currentHP = hp;
}

void Player::setCoins(const int &coins) {
    m_Coins = coins;
}