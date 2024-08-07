#pragma once
#include <string>
#include "Job.h"
#include <memory>
using std::string;
using std::shared_ptr;
class JobFactory{
public:
    shared_ptr<Job> create(string job);
};
