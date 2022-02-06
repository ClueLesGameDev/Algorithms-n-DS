#include "SLL.h"

//to keep count for the no. of links
int count = 0;

void InsertBeg(Node** root, int value)
{
	Node* tempNode = new Node;
	tempNode->data = value;
	if (*root == NULL)
	{
		tempNode->nextNode = NULL;
		*root = tempNode;
	}
	else
	{
		tempNode->nextNode = *root;
		*root = tempNode;
	}
	count++;
}

void InsertEnd(Node** root, int value)
{
	Node* tempNode = new Node;

	if (*root == NULL)
	{
		tempNode->data = value;
		tempNode->nextNode = NULL;
		*root = tempNode;
	}
	else
	{
		Node* traverseNode = *root;
		while (traverseNode->nextNode != NULL)
		{
			traverseNode = traverseNode->nextNode;
		}
		traverseNode->nextNode = tempNode;
		tempNode->data = value;
		tempNode->nextNode = NULL;
	}
	count++;
}

void InsertCustom(Node** root, int value, int location)
{
	if (location > count + 1)
	{
		std::cout << "location beyond " << count + 1 << " not possible" << std::endl;
		return;
	}
	Node* traverseNode = *root;
	if (location == 1)
	{
		InsertBeg(root, value);
	}
	else
	{
		for (int i = 1; i < location - 1; i++)
		{
			traverseNode = traverseNode->nextNode;
		}
		Node* tempNode = new Node;
		tempNode->data = value;
		tempNode->nextNode = traverseNode->nextNode;
		traverseNode->nextNode = tempNode;
	}

	count++;

}

void DeleteBeg(Node** root)
{
	if (*root == NULL)
	{
		std::cout << "\nList is empty";
	}
	else
	{
		Node* temp = *root;
		*root = temp->nextNode;
	}
}

void DeleteEnd(Node** root)
{
	if (*root == NULL)
	{
		std::cout << "\nList is empty";
	}
	else
	{
		Node* traverseNode = *root;
		while (traverseNode->nextNode->nextNode != NULL)
		{
			traverseNode = traverseNode->nextNode;
		}

		traverseNode->nextNode = NULL;
	}
}

void DeleteCustom(Node** root, int location)
{
	if (*root == NULL)
	{
		std::cout << "\nList is empty";
	}
	
	if (location > count)
	{
		std::cout << "location beyond " << count + 1 << " not possible" << std::endl;
		return;
	}
	
	if (location == 1)
	{
		DeleteBeg(root);
	}
	else
	{
		Node* traverseNode = *root;
		for (int i = 1; i < location - 1; i++)
		{
			traverseNode = traverseNode->nextNode;
		}
		Node* tempNode = traverseNode->nextNode;
		traverseNode->nextNode = tempNode->nextNode;

	}

}

void PrintLL(Node** root)
{
	Node* tempNode = *root;
	while (tempNode != NULL)
	{
		std::cout << tempNode->data << "\t";
		tempNode = tempNode->nextNode;
	}
	std::cout << std::endl;
}