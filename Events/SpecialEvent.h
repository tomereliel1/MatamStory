#pragma once
#include "Event.h"
#include <string>
using std::string;

class SpecialEvent :public Event{
public:
    explicit SpecialEvent(const string &type);
    string getDescription() const override;
};


