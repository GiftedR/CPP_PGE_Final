#pragma once
#include <vector>
#include "../data.h"

class Object
{
public:
	virtual void draw() = 0;
	
	void movePosition(Vector2 newpos);
	Vector2 getPosition();

protected:
	Vector2 position = {1, 1};
private:
};

