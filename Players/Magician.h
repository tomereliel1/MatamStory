#pragma once
#include "Job.h"
#include <string>
using std::string;
class Magician :public Job{
public:
    explicit Magician(string & type);

    ~Magician() override = default;
};