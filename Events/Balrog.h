#pragma once

#include "Encounter.h"

/**
 * Balrog- represents an Balrog Encounter type
 */
class Balrog : public Encounter {
public:
    /**
     * Constructor - creates an Balrog Encounter
     */
    Balrog();

    /**
     * Update the value of combatPower that raised after every fight
     *
     */
    void updateCombatPower() override;

    /**
     * Destructor - default destructor
     */
     ~Balrog() override = default ;
};

