#pragma once

#include "include.h"
#include "define.h"

class TreeNode
{
private:
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode* parent = nullptr;

	Position info;
	Position roomInfo;
	DIRECTION direction = DIRECTION::VERTICAL;
	bool connect = false;

public:
	TreeNode() = default;
	TreeNode(Position pos) : info(pos) { }

	void SetInfo(const Position& i) { info = i; }
	void SetRoomInfo(const Position& r) { roomInfo = r; }
	void SetParent(TreeNode* p) { parent = p; }
	void SetLeftNode(TreeNode* l) { left = l; }
	void SetRightNode(TreeNode* r) { right = r; }
	void SetDirection(DIRECTION dir) { direction = dir; }

	Position GetInfo() const { return info; }
	Position GetRoomInfo() const { return roomInfo; }
	TreeNode* GetLeftNode() { return left; }
	TreeNode* GetRightNode() { return right; }
	TreeNode* GetParentNode() { return parent; }

	void MakeConnection(vector<vector<int>>& generateMap);
};