#pragma once
#include <string>
#include <memory>
#include "Factory.h"
#include "Character.h"
#include "RiskTaking.h"
#include "Responsible.h"
using std::shared_ptr;
using std::string;

class CharacterFactory : public Factory<Character> {
public:
    shared_ptr<Character> create(string& type) const override;
    ~CharacterFactory() override = default;
};