#include <string>
#include "CharacterFactory.h"
#include "RiskTaking.h"
#include "Responsible.h"
#include <memory>
#include <stdexcept>

using std::string;
using std::shared_ptr;

shared_ptr<Character> CharacterFactory::create(string& type) const {
    if (type == "Responsible"){
        shared_ptr<Character> newCharacter(new Responsible(type));
        return newCharacter;
    } else if (type == "RiskTaking") {
        shared_ptr<Character> newCharacter(new RiskTaking(type));
        return newCharacter;
    }
    throw std::runtime_error("No such Character");
}
