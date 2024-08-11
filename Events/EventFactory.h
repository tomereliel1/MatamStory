#pragma once
#include <string>
#include <memory>
#include "Event.h"
using std::string;
using std::unique_ptr;
class EventFactory {
    static bool checkPack(string & type) ;
    unique_ptr<Event> createPack(string& type) const ;
public:
    unique_ptr<Event> create(string& type) const;

    ~EventFactory() = default;
};
