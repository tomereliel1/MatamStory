#pragma once
#include "Character.h"
#include "Job.h"
#include <string>
#include <memory>
using std::shared_ptr;
using std::string;

/**
 * Player - represents a player in the game
 */
class Player {
private:

protected:
    // m_name - the name of the player
    const string m_name;

    // m_level - the current level of the player
    int m_level;

    // m_force - the force points of the player
    int m_force;

    // m_job - a shared pointer to the player's job
    shared_ptr<Job> m_job;

    // m_character - a shared pointer to the player's character
    shared_ptr<Character> m_character;

    // m_maxHP - the maximum health points of the player
    int m_maxHP;

    // m_currentHP - the current health points of the player
    int m_currentHP;

    // m_coins - the amount of coins the player has
    int m_coins;

public:
    /**
     * Destructor - default destructor
     */
    ~Player() = default;

    /**
     * Gets the description of the player
     *
     * @return - description of the player
     */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
     */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
     */
    int getLevel() const;

    /**
     * Gets the force the player has
     *
     * @return - force points of the player
     */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
     */
    int getHealthPoints() const;

    /**
     * Gets the maximum health points of the player
     *
     * @return - maximum health points of the player
     */
    int getMaxHealthPoints() const;

    /**
     * Gets the combat power of the player
     *
     * @return - combat power of the player
     */
    int getCombatPower() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
     */
    int getCoins() const;

    /**
     * Gets the player's job
     *
     * @return - shared pointer to the player's job
     */
    shared_ptr<Job> getJob();

    /**
     * Gets the player's character
     *
     * @return - shared pointer to the player's character
     */
    shared_ptr<Character> getCharacter();

    /**
     * Constructor - creates a player with a name, job, and character
     *
     * @param name - the name of the player
     * @param job - shared pointer to the player's job
     * @param character - shared pointer to the player's character
     */
    Player(string name, shared_ptr<Job> job, shared_ptr<Character> character);

    /**
     * Sets the level of the player
     *
     * @param level - the new level of the player
     */
    void setLevel(const int& level);

    /**
     * Sets the force of the player
     *
     * @param force - the new force points of the player
     */
    void setForce(const int& force);

    /**
     * Sets the health points of the player
     *
     * @param HP - the new health points of the player
     */
    void setHP(const int& HP);

    /**
     * Sets the amount of coins the player has
     *
     * @param coins - the new amount of coins
     */
    void setCoins(const int& coins);

    /**
     * Updates the player's status after losing a battle
     *
     * @param damage - the amount of health points the player lose
     */
    void playerLost(int damage);

    /**
     * Comparison operator < - compares two players based on their attributes
     *
     * @param player1 - the first player to compare
     * @param player2 - the second player to compare
     * @return true if player1 is less than player2, false otherwise
     */
    friend bool operator < (const Player& player1, const Player& player2);
};
