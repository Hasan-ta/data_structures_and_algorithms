#include "SinglyLinkedList.hpp"


int main(int argc, char** argv)
{
	SinglyLinkedList<int> list1;

	list1.append(1);
	list1.append(2);
	list1.append(3);

	list1.print();
}