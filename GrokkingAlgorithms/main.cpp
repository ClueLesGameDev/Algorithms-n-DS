#include <iostream>


void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BinarySearch(int* list, int size, int value)
{
	int high = size;
	int low = 0;
	int mid = size / 2;
 
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

int* SelectionSort(int* myArray, int size)
{

	for (int i = 0; i < size; i++)
	{
		int min = i;

		for (int j =  i + 1; j < size; j++)
		{
			if (myArray[j] < myArray[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(myArray[i], myArray[min]);
		}

	}

	return myArray;

}
int main()
{
	int unsortedArray[] = { 2,7,4,5,3 };
	
	int size = sizeof(unsortedArray)/sizeof(unsortedArray[5]);
	int guess;
	
	int* sortedArray = SelectionSort(unsortedArray, size);
	
	for (int i = 0; i < size; i++)
	{
		std::cout << sortedArray[i] << "\t";
	}

	std::cout << "\nEnter the value to be searched :  ";
	std::cin >> guess;

	BinarySearch(sortedArray, size, guess);
	return 0;
}