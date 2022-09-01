#include "TreeNode.h"

void TreeNode::MakeConnection(vector<vector<int>>& generateMap)
{
    if (roomInfo.x < 0)
        return;
    float num = 50; // 무슨 num?
    if (direction == DIRECTION::HORIZONTAL)
    {
        int initY = roomInfo.y * (num / 100) + roomInfo.height * (num / 100);
        int initX = roomInfo.width;
        for (int i = initX; generateMap[initY][i] != 1; i++)
        {
            if (i > 59) break;
            generateMap[initY][i] = 2;
        }
    }
    else
    {
        int initX = roomInfo.x * (num / 100) + roomInfo.width * (num / 100);
        int initY = roomInfo.height;
        int i = initY;
		while (1)
		{
			if (generateMap[i][initX] == 1 || i > 59)
				break;
			generateMap[i][initX] = 2;
			i++;
		}
    }

    connect = true;
	if (parent->GetParentNode() == nullptr)
		return;
	parent->SetRoomInfo(parent->GetRightNode()->GetRoomInfo());
	if (parent != parent->parent->GetLeftNode())
		return;
	else
	{
		parent->MakeConnection(generateMap);
	}
}