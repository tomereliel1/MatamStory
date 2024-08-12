#pragma once
#include <string>
#include "../Players/Player.h"
using std::string;

class Event {
private:
    string m_type;
public:

    explicit Event (const string& type);
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    string getDescription() const;

    virtual void playEvent( Player& player) = 0;

    virtual ~Event() = default;
};
