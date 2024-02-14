#pragma once

struct Vector2
{
	int x;
	int y;

	Vector2 operator+(Vector2 const& op) { this->x += op.x;this->y += op.y;return *this; }
	Vector2 operator+=(Vector2 const& op) { this->x += op.x;this->y += op.y;return *this; };
};