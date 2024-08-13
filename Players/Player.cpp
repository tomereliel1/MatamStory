#include "Player.h"
#include <string>
#include <memory>
using std::shared_ptr;
using std::string;

Player::Player(string name, shared_ptr<Job> job, shared_ptr<Character> character) : m_name(name),
    m_level(1),m_force(5), m_job(job), m_character(character) {
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

int Player::getMaxHealthPoints() const {
    return m_maxHP;
}

int Player::getCoins() const {
    return m_coins;
}
int Player::getCombatPower() const {
    return m_job->getCombatPower(m_force, m_level);
}
shared_ptr<Job> Player::getJob() {
    return m_job;
}

shared_ptr<Character> Player::getCharacter() {
    return m_character;
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
    m_coins = coins;
}


void Player::playerLost(int damage) {
    if (m_currentHP - damage < 0){
        m_currentHP = 0;
    } else {
        m_currentHP -= damage;
    }
}

 bool operator < (const Player& player1, const Player& player2) {
    if (player1.m_level != player2.m_level) {
        return player1.m_level < player2.m_level;
    }
    if (player1.m_coins != player2.m_coins) {
        return player1.m_coins < player2.m_coins;
    }
    return player1.m_name < player2.m_name;
}
