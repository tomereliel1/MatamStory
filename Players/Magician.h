#pragma once
#include "Job.h"
#include <string>
using std::string;
class Magician :public Job{
public:
    explicit Magician(string & type);

    void applySolarEclipe(Player &player) override;

    ~Magician() override = default;
};