#include "SLL.h"

void PrintRev(Node** root)
{
	Node* traverseNode = *root;
	if (traverseNode->nextNode == NULL)
	{
		*root = traverseNode;
		return;
	}
	PrintRev(&traverseNode->nextNode);
	Node* tempNode = traverseNode->nextNode;
	tempNode->nextNode = traverseNode;
	traverseNode->nextNode = NULL;
}

void PrintRevNode(Node** root)
{
	Node* traverseNode = *root;
	if (traverseNode == NULL)
	{
		return;
	}
	PrintRevNode(&traverseNode->nextNode);
	std::cout << traverseNode->data << "\t";
}

int main()
{
	int choice,subChoice, location, value;

	Node* root = NULL;

	InsertBeg(&root, 10);
	InsertBeg(&root, 20);
	InsertBeg(&root, 30);
	InsertBeg(&root, 40);
	InsertBeg(&root, 50);
	InsertBeg(&root, 60);
	InsertBeg(&root, 70);
	InsertBeg(&root, 80);
	InsertBeg(&root, 90);
	
	PrintLL(&root);
	
	//PrintRevNode(&root);
	PrintRev(&root);
	PrintLL(&root);

	std::cout << "\nChoose from the options : 1)Insert 2)Delete 3)Print :  ";
	std::cin >> choice;

	switch (choice)
	{

	case 1:
		
		std::cout << "Choose from the options : 1)At th begginning 2)At custom position 3)At the end :  ";
		std::cin >> subChoice;

		switch (subChoice)
		{
		case 1:
			std::cout << "enter value to add at the beginning :  ";
			std::cin >> value;
			InsertBeg(&root, value);
			PrintLL(&root);
			break;

		case 2:
			std::cout << "enter value to add at the location :  ";
			std::cin >> value;
			std::cout << "enter location :  ";
			std::cin >> location;
			InsertCustom(&root, value, location);
			PrintLL(&root);
			break;

		case 3:
			std::cout << "enter value to add at the end :  ";
			std::cin >> value;
			InsertEnd(&root, value);
			PrintLL(&root);
			break;

		default:
			break;

		}
	case 2:

		std::cout << "Choose from the options : 1)At th begginning 2)At custom position 3)At the end :  ";
		std::cin >> subChoice;

		switch (subChoice)
		{
		case 1:
			DeleteBeg(&root);
			PrintLL(&root);
			break;

		case 2:
			std::cout << "enter location :  ";
			std::cin >> location;
			value = 10;
			InsertBeg(&root, value);
			PrintLL(&root);
			value = 20;
			InsertBeg(&root, value);
			PrintLL(&root);
			value = 30;
			InsertBeg(&root, value);
			PrintLL(&root);
			value = 40;
			InsertBeg(&root, value);
			PrintLL(&root);
			value = 50;
			InsertBeg(&root, value);
			PrintLL(&root);
			DeleteCustom(&root, location);
			PrintLL(&root);
			break;

		case 3:
			DeleteEnd(&root);
			PrintLL(&root);
			break;

		default:
			break;
		
		}
	
	case 3:
		PrintLL(&root);

	default:
		break;
		
	}
	

	return 0;
}