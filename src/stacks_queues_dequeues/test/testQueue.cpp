#include <iostream>
#include "Queue.hpp"

int main (int argc, char** argv)
{
	Queue<int> queue1;

	std::cout << "QueueEmpty? " << queue1.isEmpty() << std::endl;
	for (int i = 0; i < 16; ++i)
		queue1.enqueue(i);
	std::cout << "QueueEmpty? " << queue1.isEmpty() << std::endl;
	for (int i = 0; i < 16; ++i)
	{
		int a = queue1.dequeue();
		std::cout << a << std::endl;
	}
	std::cout << "QueueEmpty? " << queue1.isEmpty() << std::endl;

	return 0;
}