#pragma once
#include <string>
#include "../Players/Player.h"
using std::string;

class Event {
protected:
    string m_type;
public:

    explicit Event (const string& type);
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const = 0;

    virtual string playEvent( Player& player) = 0;

    virtual ~Event() = default;
};
