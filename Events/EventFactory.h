#pragma once
#include <string>
#include <memory>
#include <map>
#include <functional>
#include <fstream>
#include "Event.h"
using std::string;
using std::unique_ptr;


//EventFactory - responsible for creating events
class EventFactory {
private:
    //A map that associates event names with constructor
    std::map<string, std::function<unique_ptr<Event>()>> m_creators;

    /**
     * Creating a pack of monsters
     *
     * @param file - the stream to read from
     *
     * @return - unique pointer to the pack object
     */
    unique_ptr<Event> createPack(std::istream & file) const;
public:
    /**
     * Constructor - define the map keys and values
     *
     */
    EventFactory();

    /**
     * Create an event
     *
     * @param file - the stream to read from
     *
     * @return - unique pointer to the event
     */
    unique_ptr<Event> create(std::istream & file) const;

    /**
    * Destructor - default destructor
    */
    ~EventFactory() = default;
};
