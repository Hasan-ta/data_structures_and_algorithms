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

	std::cout << "*********************************************" << std::endl;

	Dequeue<double> dequeue2;
	
	for (int i = 0; i < 16; ++i)
	{
		dequeue2.addRear(i+1);
	}

	for (int i = 0; i < 10; ++i)
	{
		int a = dequeue2.removeFront();
		std::cout << a << std::endl;
	}
	for (int i = 10; i < 16; ++i)
	{
		int a = dequeue2.removeRear();
		std::cout << a << std::endl;
	}


	return 0;
}