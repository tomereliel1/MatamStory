#pragma once

#include <string>
#include <memory>
using std::string;
using std::shared_ptr;

/**
 * Factory - an abstract base class for creating objects of type T
 */
template <typename T>
class Factory {
public:
    /**
     * create - pure virtual function to create an object of type T
     *
     * @param type - the type of object to create
     * @return - a shared pointer to the created object
     */
    virtual shared_ptr<T> create(const string& type) = 0;

    /**
     * Destructor - default destructor for the Factory class
     */
    virtual ~Factory() = default;
};
