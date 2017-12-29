#include <iostream>
#include "DynamicArray.hpp"
#include <time.h>
#include <math.h>


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
		totalTime += opTimes[i];
	}

	std::cout << "Number of trials: " << opTimes.size() << std::endl;
	std::cout << "Average Time Spent: " << totalTime/opTimes.size() << std::endl;

	return 0;
}