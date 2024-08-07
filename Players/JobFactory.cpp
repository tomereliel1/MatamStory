#include <string>
#include "JobFactory.h"
#include "Warrior.h"
#include "Magician.h"
#include "Archer.h"
#include <memory>
#include <stdexcept>

using std::string;
using std::shared_ptr;

shared_ptr<Job> JobFactory::create(std::string job) {
    if (job == "Warrior"){
        shared_ptr<Job> newJob(new Warrior(job));
        return newJob;
    } else if (job == "Magician"){
        shared_ptr<Job> newJob(new Magician(job));
        return newJob;
    } else if (job == "Archer"){
        shared_ptr<Job> newJob(new Archer(job));
        return newJob;
    }
    throw std::runtime_error("No such Job");
}
