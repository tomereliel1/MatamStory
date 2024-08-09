#pragma once
#include <string>
#include <memory>
#include "Factory.h"
#include "Character.h"
#include "RiskTaking.h"
#include "Responsible.h"
using std::shared_ptr;
using std::string;
using std::make_shared;

class CharacterFactory : public Factory<Character> {
    shared_ptr<Character> m_riskTaking = make_shared<RiskTaking>();
    shared_ptr<Character> m_responsible = make_shared<Responsible>();
public:
    shared_ptr<Character> create(string& type) const override;
    ~CharacterFactory() override = default;
};
