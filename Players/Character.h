#pragma once
#include <string>
using std::string;
class Character{
protected:
    string m_type;

public:
    explicit Character(string type);
    virtual string getType() const;
    virtual ~Character() = default;
};