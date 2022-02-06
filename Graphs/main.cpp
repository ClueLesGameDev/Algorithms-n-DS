#include <unordered_map>
#include <stack>
#include <queue>
#include<iostream>

/*
* struct Node
{
	int data;
	Node* nextNode;
};

Node* root = NULL;

void InsertBeg(int value)
{
	Node* tempNode = new Node;
	tempNode->data = value;
	if (root == NULL)
	{
		tempNode->nextNode = NULL;
		root = tempNode;
	}
	else
	{
		tempNode->nextNode = root;
		root = tempNode;
	}
}

void PrintRev(Node* head)
{
	if (head->nextNode == NULL)
	{
		root = head;
		return;
	}
	PrintRev(head->nextNode);
	Node* temp = head->nextNode;
	temp->nextNode = head;
	head->nextNode = NULL;
}

void PrintLL()
{
	Node* tempNode = root;
	while (tempNode != NULL)
	{
		std::cout << tempNode->data << "\t";
		tempNode = tempNode->nextNode;
	}
	std::cout << std::endl;
}
*/

void DFS(std::unordered_map<char, std::vector<char>>* myAdjList, char startNode)
{
	std::stack<char> dfs;
	dfs.push(startNode);

	while (!dfs.empty())
	{
		char current = dfs.top();
		std::cout << current << "\t";
		dfs.pop();
		for (auto i : (*myAdjList)[current])
		{
			dfs.push(i);
		}
	}
}

void BFS(std::unordered_map<char, std::vector<char>>* myAdjList, char startNode)
{
	std::queue<char> bfs;
	bfs.push(startNode);

	while (!bfs.empty())
	{
		char current = bfs.front();
		std::cout << current << "\t";
		bfs.pop();
		for (auto i : (*myAdjList)[current])
		{
			bfs.push(i);
		}
	}
}

int main()
{
	
	/*
	* InsertBeg(10);
	InsertBeg(20);
	InsertBeg(30);
	InsertBeg(40);
	InsertBeg(50);
	InsertBeg(60);
	InsertBeg(70);
	InsertBeg(80);
	InsertBeg(90);
	PrintLL();

	PrintRev(root);
	std::cout << "\n\n\n";
	PrintLL();
	*/
	
	std::unordered_map<char, std::vector<char>> adjList;

	adjList['a'] = { 'b','c' };
	adjList['b'] = { 'd' };
	adjList['c'] = { 'e' };
	adjList['d'] = { 'f' };
	adjList['e'] = {};
	adjList['f'] = {};

	std::cout << "Depth First Traversal :  ";
	DFS(&adjList, 'a');
	std::cout << std::endl;

	std::cout << "Breadh First Traversal :  ";
	BFS(&adjList, 'a');
	std::cout << std::endl;	
	return 0;
}