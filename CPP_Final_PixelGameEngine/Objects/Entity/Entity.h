#pragma once
#include <string>
#include "../Object.h"
class Entity :
    public Object
{
public:
    float getspeed() { return speed; };
protected:
    float speed = 200.0;
private:
};

