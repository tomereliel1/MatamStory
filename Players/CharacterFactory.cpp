#include <string>
#include "CharacterFactory.h"
#include <memory>
#include <stdexcept>

using std::string;
using std::shared_ptr;

shared_ptr<Character> CharacterFactory::create(string& type) const {
    if (type == "Responsible"){
        return m_responsible;
    } else if (type == "RiskTaking") {
        return m_riskTaking;
    }
    throw std::runtime_error("No such Character");
}
