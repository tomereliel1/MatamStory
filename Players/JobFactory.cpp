#include <string>
#include "JobFactory.h"
#include <memory>
#include <stdexcept>

using std::string;
using std::shared_ptr;

shared_ptr<Job> JobFactory::create(string& type) const {
    if (type == "Warrior"){
        return m_warrior;
    } else if (type == "Magician"){
        return m_magician;
    } else if (type == "Archer"){
        return m_archer;
    }
    throw std::runtime_error("No such Job");
}

