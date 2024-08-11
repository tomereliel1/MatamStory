#pragma once

#include <string>
#include <memory>
#include <map>
#include "Factory.h"
#include "Job.h"

using std::shared_ptr;
using std::string;
using std::make_shared;

class JobFactory : public Factory<Job> {
private:
    std::map<string, shared_ptr<Job>> m_jobs;
public:
    JobFactory();
    shared_ptr<Job> create(const string &type) override;
    ~JobFactory() override = default;
};

