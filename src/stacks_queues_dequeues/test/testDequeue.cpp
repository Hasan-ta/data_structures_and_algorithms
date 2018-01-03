#include <iostream>
#include "Dequeue.hpp"

int main (int argc, char** argv)
{
	Dequeue<int> dequeue1;

	for (int i = 0; i < 16; ++i)
		dequeue1.addRear(i);
	for (int i = 0; i < 16; ++i)
	{
		int a = dequeue1.removeRear();
		std::cout << a << std::endl;
	}
	// std::cout << "QueueEmpty? " << queue1.isEmpty() << std::endl;

	return 0;
}