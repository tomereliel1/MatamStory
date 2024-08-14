#pragma once

#include "Event.h"
using std::string;

//Represents a type of Events
class SpecialEvent : public Event {
public:
    /**
     * Constructor - creates an SpecialEvent with a type
     *
     * @param type - the type of the SpecialEvent
     *
     */
    explicit SpecialEvent(const string &type);

    /**
     * Gets the description of the event
     *
     * @return - description of the event
     */
    string getDescription() const override;

    /**
     * Destructor - default destructor
     */
    ~SpecialEvent() override = default;
};


