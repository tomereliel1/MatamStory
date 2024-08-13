#include <string>
#include "JobFactory.h"
#include <memory>
#include <stdexcept>
#include "Warrior.h"
#include "Magician.h"
#include "Archer.h"
#include <iostream>
using std::string;
using std::shared_ptr;

JobFactory::JobFactory() {
    m_jobs["Warrior"] = make_shared<Warrior>();
    m_jobs["Magician"] = make_shared<Magician>();
    m_jobs["Archer"] = make_shared<Archer>();
}

shared_ptr<Job> JobFactory::create(const string& type){
    //std::cout << "Job is " << type << std::endl;
    if (m_jobs.find(type) != m_jobs.end()){
        return m_jobs[type];
    } else {
        throw std::runtime_error("Invalid Players File");
    }
}

