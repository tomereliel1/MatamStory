#pragma once
#include "Character.h"
#include <string>
using std::string;
class RiskTaking :public Character{
public:
    explicit RiskTaking(string& type);

    ~RiskTaking() override = default;
};
