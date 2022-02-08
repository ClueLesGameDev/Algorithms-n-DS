#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
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

void DFS(std::unordered_map<char, std::vector<char>>* myAdjList, char startNode, std::unordered_set<char>* visited)
{
	
	std::stack<char> dfs;
	dfs.push(startNode);

	while (!dfs.empty())
	{
		
		char current = dfs.top();
		
		if (visited->find(current) != visited->end())
		{
			dfs.pop();
			continue;
		}

		visited->insert(current);
		std::cout << current << "\t";
		dfs.pop();
		for (auto i : (*myAdjList)[current])
		{
			dfs.push(i);
		}
	}
	
	/*-----------------Recursion------------------
	
	if ((*myAdjList)[startNode].empty())
	{
		return;
	}
	char current = startNode;
	std::cout << current << "\t";
	for (auto i : (*myAdjList)[current])
	{
		DFS(myAdjList, i, visited);
	}	

	--------------------------------------------*/

	
}

void BFS(std::unordered_map<char, std::vector<char>>* myAdjList, char startNode)
{
	std::queue<char> bfs;
	bfs.push(startNode);
	std::unordered_set<char> visited;
	while (!bfs.empty())
	{
		char current = bfs.front();
		if (visited.find(current) != visited.end())
		{
			bfs.pop();
			continue;
		}
		visited.insert(current);
		std::cout << current << "\t";
		bfs.pop();
		for (auto i : (*myAdjList)[current])
		{
			bfs.push(i);
		}
	}
}

bool HasPathBFS(std::unordered_map<char, std::vector<char>>* myAdjList, char startNode, char myNode)
{
	
	std::queue<char> bfs;
	bfs.push(startNode);
	
	while (!bfs.empty())
	{
		if (bfs.front() == myNode)
		{
			return true;
		}
		else
		{
			char current = bfs.front();
			bfs.pop();
			for (auto i : (*myAdjList)[current])
			{
				bfs.push(i);
			}
		}
	}

	return false;
}


bool HasPathDFS(std::unordered_map<char, std::vector<char>>* myAdjList, char startNode, char myNode, std::unordered_set<char>* visited)
{
	if (startNode == myNode)
	{
		return true;
	}
	if (visited->find(startNode) != visited->end())
	{
		return false;
	}

	visited->insert(startNode);
	for (auto i : (*myAdjList)[startNode])
	{
			return HasPathDFS(myAdjList, i, myNode, visited);
	}

	
}

char LargestNode(std::unordered_map<char, std::vector<char>>* myAdjList, char startNode)
{
	std::unordered_set<char> visited;
	char large = startNode;
	std::queue<char> bfs;
	bfs.push(startNode);

	while (!bfs.empty())
	{
		char current = bfs.front();
		if (visited.find(current) != visited.end())
		{
			bfs.pop();
			continue;
		}

		visited.insert(current);
		bfs.pop();
		for (auto i : (*myAdjList)[current])
		{
			if (large < i)
			{
				large = i;
			}
			
			bfs.push(i);
		}
	}
	
	return large;
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
	std::unordered_set<char> visited;

	adjList['i'] = { 'j','k' };
	adjList['j'] = { 'i' };
	adjList['k'] = { 'i','m','l'};
	adjList['m'] = { 'k' };
	adjList['l'] = { 'k' };
	adjList['o'] = { 'n' };
	adjList['n'] = { 'o' };

	std::cout << "Depth First Traversal :  ";
	DFS(&adjList, 'k', &visited);
	std::cout << std::endl;

	std::cout << "Breadh First Traversal :  ";
	BFS(&adjList, 'k');
	std::cout << std::endl;	

	bool hasPath = HasPathDFS(&adjList, 'j', 'n', &visited);

	char largest = LargestNode(&adjList, 'k');

	std::cout << "\nLargest node existing = " << largest << std::endl;
	
	if (hasPath)
	{
		std::cout << "path exists" << std::endl;
	}
	else
	{
		std::cout << "path doesnt exists" << std::endl;
	}
	
	return 0;
}