#pragma once

#include "SpecialEvent.h"

using std::string;

//Represents a SpecialEvent called SolarEclipse
class SolarEclipse : public SpecialEvent {
public:
    /**
     * Constructor - create a SolarEclipse typed event
     *
     */
    SolarEclipse();

    /**
     * Plays the event - player effected by SolarEclipse
     *
     * @param player - the player who effected
     *
     * @return - the outcome message
     */
    string playEvent( Player& player) override;

    /**
    * Destructor - default destructor
    */
    ~SolarEclipse() override = default;
};

