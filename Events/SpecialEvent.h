#pragma once
#include "Event.h"
#include <string>
using std::string;

class SpecialEvent :public Event{
public:

    explicit SpecialEvent(string & type);
};

