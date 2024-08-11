#pragma once
#include <string>
#include <memory>
#include <map>
#include "Factory.h"
#include "Character.h"

using std::shared_ptr;
using std::string;
using std::make_shared;

class CharacterFactory : public Factory<Character> {
private:
    std::map<string, shared_ptr<Character>> m_characters;
public:
    CharacterFactory();
    shared_ptr<Character> create(const string& type) override;
    ~CharacterFactory() override = default;
};
