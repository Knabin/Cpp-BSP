#include "GenerateMap.h"

#include <random>

#include "TreeNode.h"

void GenerateMap::Start()
{
	const int MAX_X = 61;
	const int MAX_Y = 61;

	genMap.resize(MAX_Y);

	for (int i = 0; i < MAX_Y; ++i)
	{
		vector<int> vec;
		vec.resize(MAX_X);

		genMap[i] = vec;
	}

	root = new TreeNode();
	root->SetInfo(Position{0, 0, MAX_X, MAX_Y});

	MakeTree(root);

	while (1)
	{
		MakeConnect(root);
		if (root->GetLeftNode()->GetRoomInfo().width > 0)
			break;
	}

	for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
		{
			COORD pos = { j * 2, i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			printf("%d", genMap[i][j]);
		}
	}
}

void GenerateMap::MakeTree(TreeNode* node)
{
	Position pos1, pos2;

	DIRECTION dir;
	int dirRand = rand() % 2;
	float num1 = rand() % 20 + 40;			// 무슨 숫자인지?

	if (dirRand == 0)
	{
			int num2 = (node->GetInfo().width - node->GetInfo().x) * (num1 / 100);	// 무슨 숫자인지?

			dir = DIRECTION::HORIZONTAL;

			pos1 = { node->GetInfo().x, node->GetInfo().y, node->GetInfo().width - num2, node->GetInfo().height };
			pos2 = { node->GetInfo().width - num2, node->GetInfo().y, node->GetInfo().width, node->GetInfo().height };
	}
	else
	{
			int num2 = (node->GetInfo().height - node->GetInfo().y) * (num1 / 100);

			dir = DIRECTION::VERTICAL;

			pos1 = { node->GetInfo().x, node->GetInfo().y, node->GetInfo().width, node->GetInfo().height - num2 };
			pos2 = { node->GetInfo().x, node->GetInfo().height - num2, node->GetInfo().width, node->GetInfo().height };
	}

	if (pos1.width - pos1.x < 10 ||
		pos1.height - pos1.y < 10 ||
		pos2.width - pos2.x < 10 ||
		pos2.height - pos2.y < 10)
	{
		int a = rand() % 4 + 1;
		int b = rand() % 4 + 1;
		int c = rand() % 4 + 1;
		int d = rand() % 4 + 1;
		for (int i = node->GetInfo().y + c; i < node->GetInfo().height - d; i++)
		{
			for (int j = node->GetInfo().x + a; j < node->GetInfo().width - b; j++)
			{
				genMap[i][j] = 1;
			}
		}
		node->SetRoomInfo(Position(node->GetInfo().x + a,
			node->GetInfo().y + c,
			node->GetInfo().width - b,
			node->GetInfo().height - d));
		return;
	}

	node->SetLeftNode(new TreeNode(pos1));
	node->GetLeftNode()->SetParent(node);
	node->GetLeftNode()->SetDirection(dir);
	MakeTree(node->GetLeftNode());

	node->SetRightNode(new TreeNode(pos2));
	node->GetRightNode()->SetParent(node);
	node->GetRightNode()->SetDirection(dir);
	MakeTree(node->GetRightNode());
}

void GenerateMap::MakeConnect(TreeNode* node)
{
	if (!node->GetLeftNode())
	{
		if (node->GetParentNode()->GetLeftNode() == node)
			node->MakeConnection(genMap);
	}
	else if (node->GetRoomInfo().width > 0)
	{
		if (!node->GetParentNode())
			return;
		if (node->GetParentNode()->GetLeftNode() == node)
			node->MakeConnection(genMap);
	}
	else
	{
		MakeConnect(node->GetLeftNode());
		MakeConnect(node->GetRightNode());
	}
}