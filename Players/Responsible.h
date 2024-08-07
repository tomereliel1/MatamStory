#pragma once
#include "Character.h"
#include <string>
using std::string;
class Responsible :public Character{
public:
    explicit Responsible(string& type);

    ~Responsible() override = default;
};
