#include "SinglyLinkedList.hpp"


int main(int argc, char** argv)
{
	SinglyLinkedList<int> list1;

	for (int i = 0; i < 16; ++i)
	{
		list1.append(i);
	}
	list1.print();

	list1.remove(5);
	list1[14] = 100;
	list1.insert(9, 200);

	int sss = list1.size();
	for (int i = 0; i < sss; ++i)
	{
		int a = list1.pop();
		std::cout << "pop: " << a << std::endl;
 	}

 	return 0;
}