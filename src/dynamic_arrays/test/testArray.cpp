#include <iostream>
#include "DynamicArray.hpp"

int main (int argc, char** argv)
{
	DynamicArray<int> array1(2,0);

	for (int i = 0; i < 32; ++i)
	{
		array1.append(i);
	}
}