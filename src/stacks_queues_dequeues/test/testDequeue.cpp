#include <iostream>
#include "Dequeue.hpp"

int main (int argc, char** argv)
{
	Dequeue<int> dequeue1;
	
	std::cout << "QueueEmpty? " << dequeue1.isEmpty() << std::endl;
	for (int i = 0; i < 16; ++i)
	{
		dequeue1.addRear(i+1);
		std::cout << "Queue Size: " << dequeue1.size() << std::endl;
	}
	std::cout << "QueueEmpty? " << dequeue1.isEmpty() << std::endl;
	for (int i = 0; i < 16; ++i)
	{
		int a = dequeue1.removeRear();
		std::cout << a << std::endl;
		std::cout << "Queue Size: " << dequeue1.size() << std::endl;
	}
	std::cout << "QueueEmpty? " << dequeue1.isEmpty() << std::endl;

	return 0;
}