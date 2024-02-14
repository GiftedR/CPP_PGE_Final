#pragma once
#include "../Object.h"
#include <string>
class Entity :
    public Object
{
public:
    virtual void draw(std::string spriteloc);
protected:
private:
};

