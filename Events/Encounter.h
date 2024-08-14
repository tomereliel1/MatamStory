#pragma once

#include "Event.h"
#include <string>

using std::string;

/**
 * Encounter - represents an Monster Encounter type of Event
 */
class Encounter : public Event {
protected:
    //The combatPower of the Monster
    int m_combatPower;
    //The loot gained when winning the monster
    int m_loot;
    //The damage taken when losing to the monster
    int m_damage;
public:
    /**
     * Constructor - creates an Encounter with a type, combatPower, loot and damage
     *
     * @param type - the type of the Encounter
     *
     */
    explicit Encounter(const string &type);

    /**
     * Gets the damage of the monster
     *
     * @return - damage of the monster
     */
    int getDamage() const;

    /**
     * Gets the combatPower of the monster
     *
     * @return - combatPower of the monster
     */
    int getCombatPower() const;

    /**
     * Gets the loot of the monster
     *
     * @return - loot of the monster
     */
    int getLoot() const;

    /**
     * Plays the event - fight against the monster
     *
     * @param player - the player who fight the monster
     *
     * @return - the outcome message
     */
    string playEvent(Player &player) override;

    /**
     * Update the value of combatPower that raised after every fight
     *
     */
    virtual void updateCombatPower();

    /**
     * Gets the description of the monster
     *
     * @return - description of the monster
     */
    string getDescription() const override;

    /**
     * Destructor - default destructor
     */
    ~Encounter() override = default;
};

