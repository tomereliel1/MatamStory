#pragma once
#include <string>
#include <memory>
#include "Factory.h"
#include "Job.h"
#include "Warrior.h"
#include "Magician.h"
#include "Archer.h"
using std::shared_ptr;
using std::string;




class JobFactory : public Factory<Job> {
public:
   shared_ptr<Job> create(string& type) const override;
   ~JobFactory()() override = default;
};

