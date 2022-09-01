#pragma once
#include "define.h"
#include "include.h"

class TreeNode;

class GenerateMap
{
private:
	Position info;
	TreeNode* root;
	vector<vector<int>> genMap;
	
public:
	GenerateMap() = default;
	GenerateMap(Position pos) : info(pos) { }

	void Start();
	void MakeTree(TreeNode* node);
	void MakeConnect(TreeNode* node);
};