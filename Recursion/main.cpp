#include <iostream>

void Swap(int& a, int& b)
{
	a = a + b;
	b = a;
	a = a - b;
}

int Sum(int* list, int size)
{
	int sum = list[size];
	
	if (size == 0)
	{
		return sum;
	}
	
	sum += Sum(list, size - 1);
}

int Max(int* list, int size)
{
	if (size == 1)
	{
		return list[0];
	}

	return std::max(list[size], Max(list, size -1));
}

void BinarySearch(int* list, int l, int h, int value)
{
	int high = h;
	int low = l;
	int mid = (l + h) / 2;

	if (mid >= 1)
	{
		if (list[mid] == value)
		{
			std::cout << "found the element at : " << mid + 1 << "th position" << std::endl;
			return;
		}

		if (value > list[mid])
		{
			BinarySearch(list, mid + 1,high, value);
		}

		else if (value < list[mid])
		{
			BinarySearch(list, l, mid - 1, value);
		}
	}

	std::cout << "Element not Found \n";
	return;

}

int* QuickSort(int* myArray, int low, int high)
{
	if (low < high)
	{

		int pivot = high;
		int lowIndex = low - 1;

		for (int i = low; i <= high - 1; i++)
		{
			if (myArray[i] <= myArray[pivot])
			{
				lowIndex++;
				Swap(myArray[lowIndex], myArray[i]);
			}
		}
		Swap(myArray[lowIndex + 1], myArray[high]);

		QuickSort(myArray, low, lowIndex - 1);
		QuickSort(myArray, lowIndex + 1, high);
	}
	
	return myArray;
}

int main()
{
	int myArray[] = { 2,4,3,11,9,2 };

	int n = sizeof(myArray) / sizeof(myArray[0]);

	int* sortedArray = QuickSort(myArray, 0, n-1);

	for (int i = 0; i < n; i++)
	{
		std::cout << sortedArray[i] << "\t";
	}
	
	//std::cout << "Sum of the given array thrugh recursion :  " << Sum(myArray, 5) << std::endl;
	
	//std::cout << "Max element in the given array thrugh recursion :  " << Max(myArray, 5) << std::endl;
	return 0;

}