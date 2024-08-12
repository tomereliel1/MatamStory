#pragma once
#include <string>
#include <memory>
#include <map>
#include <functional>
#include <fstream>
#include "Event.h"
using std::string;
using std::unique_ptr;
class EventFactory {
private:
    std::map<string, std::function<unique_ptr<Event>()>> m_creators;
    unique_ptr<Event> createPack(std::ifstream & file) const;
public:
    EventFactory();
    unique_ptr<Event> create(std::ifstream & file) const;
    ~EventFactory() = default;
};
