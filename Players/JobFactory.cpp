#include <string>
#include "JobFactory.h"
#include <memory>
#include <stdexcept>

using std::string;
using std::shared_ptr;

shared_ptr<Job> JobFactory::create(string& type) const {
    if (type == "Warrior"){
        shared_ptr<Job> newJob(new Warrior(type));
        return newJob;
    } else if (type == "Magician"){
        shared_ptr<Job> newJob(new Magician(type));
        return newJob;
    } else if (type == "Archer"){
        shared_ptr<Job> newJob(new Archer(type));
        return newJob;
    }
    throw std::runtime_error("No such Job");
}

