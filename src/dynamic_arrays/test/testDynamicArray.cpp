#include <iostream>
#include "DynamicArray.hpp"


void printArrayInfo(const DynamicArray<int> a)
{
	std::cout << "*******************************************\n"
		"Array Info: \n"
		"\tArray Size: " << a.size() << "\n"
		"\tArray Capacity: " << a.capacity() << std::endl;

	for (int i = 0; i < a.size(); ++i)
	{
		std::cout << "\tarray[" << i << "]: " << a[i] << std::endl;
	}

	// Error Compiling (const object)
	// a[0] = 5;
}
int main (int argc, char** argv)
{
	DynamicArray<int> array1(2,0);

	printArrayInfo(array1);
	for (int i = 0; i < 32; ++i)
	{
		array1.append(i);
		printArrayInfo(array1);
	}

	array1[10] = 500;
	printArrayInfo(array1);

	return 0;
}