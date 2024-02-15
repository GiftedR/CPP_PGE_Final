#pragma once
#include "olcPixelGameEngine.h"
#include <string>

template <class T> struct V2Gen
{
	T x;
	T y;

	V2Gen(T h, T v) { x = h; y = v; }

	V2Gen operator+(V2Gen const& op) { this->x += op.x; this->y += op.y; return *this; }
	V2Gen operator+=(V2Gen const& op) { this->x += op.x; this->y += op.y; return *this; };
	V2Gen operator-(V2Gen const& op) { this->x -= op.x; this->y -= op.y; return *this; }
	V2Gen operator-=(V2Gen const& op) { this->x -= op.x; this->y -= op.y; return *this; };

	std::string toString() {
		return '[' + std::to_string(x) + ',' + std::to_string(y) + ']';
	}
};

typedef V2Gen<float> Vector2;
typedef V2Gen<int> Vector2i;
typedef V2Gen<unsigned int> Vector2u;
typedef V2Gen<double> Vector2d;