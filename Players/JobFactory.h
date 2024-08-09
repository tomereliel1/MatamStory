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
using std::make_shared;

class JobFactory : public Factory<Job> {
    shared_ptr<Job> m_warrior = make_shared<Warrior>();
    shared_ptr<Job> m_magician = make_shared<Magician>();
    shared_ptr<Job> m_archer = make_shared<Archer>();
public:
   shared_ptr<Job> create(string& type) const override;
   ~JobFactory() override = default;
};

