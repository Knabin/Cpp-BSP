#pragma once

enum class DIRECTION
{
	VERTICAL,
	HORIZONTAL,
};

struct Position
{
	float x, y, width, height;
	
	Position(float _x, float _y, float _width, float _height)
	: x(_x), y(_y), width(_width), height(_height)
	{
		// Nothing to do
	}

	Position() = default;
	~Position() = default;
};