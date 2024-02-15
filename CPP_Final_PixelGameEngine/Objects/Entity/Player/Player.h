#pragma once
#include "../Entity.h"
class Player :
    public Entity
{
public:
    Player() {
        setSkin("Objects/Entity/DefaultEntity.png");
        speed = 200.0;
    }
};

