#pragma once

#include <string>
#include "../Players/Player.h"

using std::string;

/**
 * Event - represents an event of the game
 */
class Event {
protected:
    //type of the event
    string m_type;
public:
    /**
     * Constructor - creates an Event with a type
     *
     * @param type - the type of the Event
     *
     */
    explicit Event(const string &type);

    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const = 0;

    /**
     * Plays the event
     *
     * @param player - the player who plays the event
     *
     * @return - the outcome message
     */
    virtual string playEvent(Player &player) = 0;

    /**
     * Destructor - default destructor
     */
    virtual ~Event() = default;
};
