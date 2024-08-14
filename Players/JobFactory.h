#pragma once

#include <string>
#include <memory>
#include <map>
#include "Factory.h"
#include "Job.h"

using std::shared_ptr;
using std::string;
using std::make_shared;

/**
 * JobFactory - a class responsible for creating Job objects
 */
class JobFactory : public Factory<Job> {
private:
    // m_jobs - a map that stores Job objects identified by their type
    std::map<string, shared_ptr<Job>> m_jobs;

public:
    /**
     * Constructor - initializes the JobFactory
     */
    JobFactory();

    /**
     * create - creates a Job object based on the specified type
     *
     * @param type - the type of Job to create
     * @return - a shared pointer to the created Job object
     */
    shared_ptr<Job> create(const string &type) override;

    /**
     * Destructor - default destructor for the JobFactory
     */
    ~JobFactory() override = default;
};
