#pragma once
#include "Job.h"
#include <string>
using std::string;
class Archer :public Job{
public:
    explicit Archer();

    int getCoins() const override;
    ~Archer() override = default;
};

