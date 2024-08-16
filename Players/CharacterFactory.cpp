#include <memory>
#include <stdexcept>
#include "CharacterFactory.h"
#include "Responsible.h"
#include "RiskTaking.h"

using std::string;
using std::shared_ptr;

const string RISK_TAKING_TYPE = "RiskTaking";
const string RESPONSIBLE = "Responsible";
const string INVALID_FILE = "Invalid Players File";


CharacterFactory::CharacterFactory() {
    m_characters[RISK_TAKING_TYPE] = make_shared<RiskTaking>();
    m_characters[RESPONSIBLE] = make_shared<Responsible>();
}

shared_ptr<Character> CharacterFactory::create(const string &type) {
    if (m_characters.find(type) != m_characters.end()) {
        return m_characters[type];
    }
    else {
        throw std::runtime_error(INVALID_FILE);
    }
}
