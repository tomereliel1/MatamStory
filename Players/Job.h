#pragma once
#include <string>
using std::string;

class Player; // Forward declaration of the Player class

/**
 * Job - represents a job type that a player can have
 */
class Job {
protected:
    // m_type - the type of the job
    string m_type;
    bool m_closeRanged;
public:
    /**
     * Constructor - creates a job with a specific type
     *
     * @param type - the type of the job
     * @param closeRanged - whether the job is close range , default false
     */
    explicit Job(const string& type, bool closeRanged = false);

    /**
     * Gets the maximum health points for the job
     *
     * @return - maximum health points
     */
    virtual int getMaxHP() const;

    /**
     * Gets the amount of coins associated with the job
     *
     * @return - coins for the job
     */
    virtual int getCoins() const;

    /**
     * Calculates the combat power of the job based on force and level
     *
     * @param force - the force points of the player
     * @param level - the current level of the player
     * @return - the combat power
     */
    virtual int getCombatPower(int force, int level) const;

    /**
     * Applies the effect of a solar eclipse on the player
     *
     * @param player - the player affected by the solar eclipse
     * @return - some effect value, specific to the implementation
     */
    virtual int applySolarEclipse(Player &player);

    /**
     * Gets the type of the job
     *
     * @return - the type of the job
     */
    string getType() const;

    /**
     * Updates the player's status after winning a battle
     *
     * @param player - the player who won
     * @param loot - the amount of loot the player receives
     */
    virtual void playerWon(Player &player, int loot) const;

    /**
     * Destructor - default destructor
     */
    virtual ~Job() = default;

    /**
     * Updates the player's status after losing a battle
     *
     * @param player - the player who lost
     * @param damage - the amount of damage the player taken
     */
    void playerLost(Player& player, int damage);

};
