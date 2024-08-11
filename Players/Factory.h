#pragma once
#include <string>
#include <memory>
using std::string;
using std::shared_ptr;


template <typename T>
class Factory {
public:
    virtual shared_ptr<T> create(const string& type) = 0;
    virtual ~Factory() = default;
};
