#include "JobFactory.h"
#include <memory>
#include <stdexcept>
#include "Warrior.h"
#include "Magician.h"
#include "Archer.h"

using std::string;
using std::shared_ptr;

const string ARCHER_TYPE = "Archer";
const string MAGICIAN_TYPE = "Magician";
const string WARRIOR_TYPE = "Warrior";
const string INVALID_FILE = "Invalid Players File";

JobFactory::JobFactory() {
    m_jobs[WARRIOR_TYPE] = make_shared<Warrior>();
    m_jobs[MAGICIAN_TYPE] = make_shared<Magician>();
    m_jobs[ARCHER_TYPE] = make_shared<Archer>();
}

shared_ptr<Job> JobFactory::create(const string &type) {
    if (m_jobs.find(type) != m_jobs.end()) {
        return m_jobs[type];
    }
    else {
        throw std::runtime_error(INVALID_FILE);
    }
}

