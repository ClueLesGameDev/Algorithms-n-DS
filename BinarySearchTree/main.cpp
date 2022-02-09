#include<iostream>
#include<queue>

struct BSTNode
{
	int data;
	BSTNode* leftNode;
	BSTNode* rightNode;
};

void Insert(BSTNode** root, int value)
{
	if (*root == NULL)
	{
		BSTNode* newNode = new BSTNode();
		newNode->data = value;
		newNode->leftNode = NULL;
		newNode->rightNode = NULL;
		*root = newNode;
		return;
	}

	if (value > (*root)->data)
	{
		return Insert(&(*root)->rightNode, value);
	}
	else
	{
		return Insert(&(*root)->leftNode, value);
	}
}

void PrintDFS(BSTNode** root)
{
	if ((*root) == NULL)
	{
		return;
	}
	std::cout << (*root)->data << "\t";

	if ((*root)->leftNode != NULL)
	{
		PrintDFS(&(*root)->leftNode);
	}
	if (&(*root)->rightNode != NULL)
	{
		PrintDFS(&(*root)->rightNode);
	}

}

void PrintBFS(BSTNode** root)
{
	std::queue<BSTNode*> bfs;
	bfs.push(*root);

	while (!bfs.empty())
	{
		BSTNode* current = bfs.front();
		std::cout << current->data << "\t";
		bfs.pop();
		if (current->leftNode != NULL)
		{
			bfs.push(current->leftNode);
		}
		if (current->rightNode != NULL)
		{
			bfs.push(current->rightNode);
		}
		
	}

}

bool SearchBST(BSTNode** root, int value)
{
	if ((*root) == NULL)
	{
		return false;
	}
	if ((*root)->data == value)
	{
		return true;
	}
	else if(value > (*root)->data)
	{
		return SearchBST(&(*root)->rightNode, value);
	}
	else
	{
		return SearchBST(&(*root)->leftNode, value);
	}

	

}
int main()
{
	BSTNode* root = NULL;

	Insert(&root, 10);
	Insert(&root, 5);
	Insert(&root, 30);
	Insert(&root, 15);
	Insert(&root, 2);
	Insert(&root, 7);
	Insert(&root, 35);

	PrintDFS(&root);

	std::cout << std::endl;

	PrintBFS(&root);

	std::cout << std::endl;

	bool hasNode = SearchBST(&root, 20);
	if (hasNode)
	{
		std::cout << "node exists";
	}
	else
	{
		std::cout << "node not found";
	}
	return 0;
}