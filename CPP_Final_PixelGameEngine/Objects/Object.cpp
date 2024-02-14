#include "Object.h"

void Object::movePosition(Vector2 newpos) { position += newpos; };

Vector2 Object::getPosition() { return position; };
