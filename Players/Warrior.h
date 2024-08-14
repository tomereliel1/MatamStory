#pragma once

#include "Job.h"
#include <string>
using std::string;

/**
 * Warrior - represents the warrior job type that a player can have
 */
class Warrior : public Job {
public:
    /**
     * Constructor - creates a Warrior job
     */
    explicit Warrior();

    /**
     * Gets the maximum health points for the warrior job
     *
     * @return - maximum health points for the warrior
     */
    int getMaxHP() const override;

    /**
     * Calculates the combat power of the warrior based on force and level
     *
     * @param force - the force points of the player
     * @param level - the current level of the player
     * @return - the combat power of the warrior
     */
    int getCombatPower(int force, int level) const override;

    /**
     * Updates the player's status after the warrior wins a battle
     *
     * @param player - the player who won
     * @param loot - the amount of loot the player receives
     */
    void playerWon(Player &player, int loot) const override;

    /**
     * Destructor - default destructor for the Warrior class
     */
    ~Warrior() override = default;
};
