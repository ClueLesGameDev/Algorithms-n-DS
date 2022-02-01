#include <iostream>
#include "BinarySearch.h"

void SelectionSort(int(&myArray)[5])
{
	int lowest = 0;
	for (int i = 1; i < 5; i++)
	{
		if (myArray[i] < myArray[lowest])
		{

		}
	}
}
int main()
{
	int unsortedArray[] = { 2,7,4,5,3 };

	SelectionSort(unsortedArray);

	return 0;
}