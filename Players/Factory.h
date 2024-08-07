#pragma once
#include <string>
#include <memory>
using std::string;
using std::shared_ptr;

#ifndef FACTORY_H
#define FACTORY_H

template <typename T>
class Factory {
public:
    virtual shared_ptr<T> create(string& type) const = 0;
    virtual ~Factory() = default;
};




#endif // FACTORY_H