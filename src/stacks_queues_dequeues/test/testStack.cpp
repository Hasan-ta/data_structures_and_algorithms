#include <iostream>
#include "Stack.hpp"

int main (int argc, char** argv)
{
	Stack<int> stack1;

	std::cout << "stackEmpty? " << stack1.isEmpty() << std::endl;

	for (int i = 0; i < 16; ++i)
		stack1.push(i);

	std::cout << "stackEmpty? " << stack1.isEmpty() << std::endl;

	for (int i = 0; i < 16; ++i)
	{
		int a = stack1.pop();
		std::cout << a << std::endl;
	}
	std::cout << "stackEmpty? " << stack1.isEmpty() << std::endl;

	return 0;
}