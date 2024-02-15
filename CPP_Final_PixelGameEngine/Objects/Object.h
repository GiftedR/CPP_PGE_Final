#pragma once
#include <vector>
#include "../data.h"

class Object
{
public:
	void movePosition(Vector2i newpos) { position += newpos; };
	Vector2i getPosition() { return position; };

	std::string getSkin() { return skin; };
	void setSkin(std::string newskin) { skin = newskin; }

protected:
	Vector2i position = { 0, 0 };
	Vector2 Velocity = { 0, 0 };
	float gravity = 1.0;
private:
	std::string skin = "Entity/DefaultEntity.png";
};

