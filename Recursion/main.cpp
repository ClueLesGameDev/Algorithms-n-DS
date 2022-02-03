#include <iostream>

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

int main()
{
	int myArray[] = { 2,4,3,11,9,2 };

	std::cout << "Sum of the given array thrugh recursion :  " << Sum(myArray, 5) << std::endl;
	
	std::cout << "Max element in the given array thrugh recursion :  " << Max(myArray, 5) << std::endl;
	return 0;

}