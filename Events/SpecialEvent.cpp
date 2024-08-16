#include "SpecialEvent.h"

using std::string;


SpecialEvent::SpecialEvent(const string &type) : Event(type) {}

string SpecialEvent::getDescription() const {
    return m_type;
}