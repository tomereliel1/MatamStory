
#pragma once
#include "Character.h"
#include "Job.h"
#include "JobFactory.h"
#include "CharacterFactory.h"
#include <string>
#include <memory>
using std::shared_ptr;
using std::string;


class Player {
private:
protected:
    const string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_currentHP;
    int m_coins;
    shared_ptr<Job> m_job;
    shared_ptr<Character> m_character;
    JobFactory m_jobFactory;
    CharacterFactory m_characterFactory;
public:
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
     * Gets the of force the player has
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
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;

    shared_ptr<Job> getJob();

    Player(string name,string job, string character);


};
