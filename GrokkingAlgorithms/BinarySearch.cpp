/*--------------------------------------------------
	Youtube Tutorial example 1 : 
	Binary search with Linear Arrays
--------------------------------------------------*/
#include<iostream>

void BinarySearch(int (&list)[100], int value)
{
	int high = sizeof(list)/sizeof(list[0]);
	int low =  0;
	

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (value == list[mid])
		{
			std::cout << "found the element at : " << mid + 1 << "th position" << std::endl;
			return;
		}
		else if (value < list[mid])
		{
			high = mid - 1;
		}
		else if (value > list[mid])
		{
			low = mid + 1;
		}

	}

	std::cout << "Element not Found \n";
	
}
