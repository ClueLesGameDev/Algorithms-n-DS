#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* nextNode;
};

//Insert at beginning
void InsertBeg(Node** root, int value);

//Insert at the End
void InsertEnd(Node** root, int value);

//Insert at a custom location
void InsertCustom(Node** root, int value, int location);

//Delete at Beginning
void DeleteBeg(Node** root);

//delete at End
void DeleteEnd(Node** root);

//Delete from a custom location
void DeleteCustom(Node** root, int location);

//Print the Linked List
void PrintLL(Node** root);