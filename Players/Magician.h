#pragma once
#include "Job.h"
#include <string>
using std::string;
class Magician :public Job{
public:
    explicit Magician();

    void applySolarEclipse(Player &player) override;

    ~Magician() override = default;
};