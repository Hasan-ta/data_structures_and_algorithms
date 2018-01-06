#include "DoublyLinkedList.hpp"
#include <iostream>


int main(int argc, char** argv)
{
	DoublyLinkedList<int> list1;

	for (int i = 0; i < 16; ++i)
	{
		list1.append(i+1);
	}
	std::cout << "List after appending 16 elements" << std::endl;
	list1.print();

	list1.push(1000);
	std::cout << "push 1000: " << std::endl;
	list1.print();

	list1.push(2000);
	std::cout << "push 2000: " << std::endl;
	list1.print();



	// list1.remove(5);
	// list1[14] = 100;
	// list1.insert(9, 200);
	// list1.print();
	// list1.insert(0, 1010);
	// std::cout << "inserting at head" << std::endl;
	// list1.print();
	// list1.insert(list1.size(), 1010);
	// std::cout << "inserting at tail" << std::endl;
	// list1.print();

	// int sss = list1.size();
	// for (int i = 0; i < sss; ++i)
	// {
	// 	int a = list1.pop();
	// 	std::cout << "pop: " << a << std::endl;
	// 	list1.print();
 // 	}

 	return 0;
}