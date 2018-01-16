#include <iostream>
#include "DynamicArray.hpp"
#include <time.h>
#include <math.h>
#include <vector>


void printArrayInfo(const DynamicArray<int>& a)
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
	DynamicArray<int> array1;
	DynamicArray<float> opTimes;

	printArrayInfo(array1);
	for (int i = 0; i < pow(2,10); ++i)
	{
		clock_t timeSpent = clock();
		array1.append(i);
		timeSpent = clock() - timeSpent;
		opTimes.append((float)timeSpent);
		// printArrayInfo(array1);
		// std::cout << "capacity: " << array1.capacity() << std::endl;
		std::cout << "Time Spent: " << (int) timeSpent << std::endl;
	}

	double totalTime = .0;
	for (int i = 0; i < opTimes.size(); ++i)
	{
		if(opTimes[i] == 0)
			totalTime++;
		else
			totalTime += opTimes[i];
	}

	std::cout << "Number of trials: " << opTimes.size() << std::endl;
	std::cout << "Average Time Spent: " << totalTime/opTimes.size() << std::endl;


	// Testing iterator functionality;

	DynamicArray<int> array2(16,0);
	DynamicArray<int>::iterator array2It;
	array2It = array2.begin();
	int counter = 0;
	for (; array2It != array2.end(); ++array2It)
	{
		*array2It = counter;
		counter++;
	}

	const DynamicArray<int> constArray2(16,0);

	DynamicArray<int>::const_iterator array2ConstIt = constArray2.begin();

	while(array2ConstIt != constArray2.end())
	{
		std::cout << *array2ConstIt << std::endl;
		array2ConstIt++;
	}

	DynamicArray<int> array3;
	array3 = array2;

	printArrayInfo(array3);

	DynamicArray<int> array4(DynamicArray<int>(16,3));

	printArrayInfo(array4);	

	std::cout << "array4.pop(): " << array4.pop() << std::endl;
	printArrayInfo(array4);	

	return 0;
}