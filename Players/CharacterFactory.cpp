#include <string>
#include <memory>
#include <stdexcept>
#include "CharacterFactory.h"
#include "Responsible.h"
#include "RiskTaking.h"
using std::string;
using std::shared_ptr;

CharacterFactory::CharacterFactory() {
    m_characters["RiskTaking"] = make_shared<RiskTaking>();
    m_characters["Responsible"] = make_shared<Responsible>();
}

shared_ptr<Character> CharacterFactory::create(const string& type) {
    if (m_characters.find(type) != m_characters.end()){
        return m_characters[type];
    } else {
        throw std::runtime_error("Invalid Players File");
    }
}
