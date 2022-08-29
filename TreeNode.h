#pragma once

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

enum class DIRECTION
{
	VERTICAL,
	HORIZONTAL,
};

class TreeNode
{
	private:
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
		Position info;
		Position roomInfo;
		DIRECTION direction = DIRECTION::VERTICAL;
		bool connect = false;

	public:
};