#include "BinarySearchTree.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	BinarySearchTree<int, char> bst1;

	bst1.put(2,'a');
	std::cout << "bst1 size : " << bst1.size() << std::endl;

	bst1.put(0,'b');
	std::cout << "bst1 size : " << bst1.size() << std::endl;

	bst1.deleteNode(2);
	std::cout << "Deleting node with key = 2" << std::endl;
	std::cout << "bst1 size : " << bst1.size() << std::endl;
	
	bst1.put(3,'c');
	std::cout << "bst1 size : " << bst1.size() << std::endl;
	std::cout << "bst1 get(0) : " << bst1.get(0)->value() << std::endl;
	std::cout << "bst1 get(2) : " << bst1.get(2)->value() << std::endl;

	bst1.put(1,'d');
	std::cout << "bst1 get(1) : " << bst1.get(1)->value() << std::endl;
	std::cout << "bst1 size : " << bst1.size() << std::endl;
	std::cout << "bst1 get(3) : " << bst1.get(3)->value() << std::endl;

	bst1.put(4,'e');
	std::cout << "bst1 size : " << bst1.size() << std::endl;
	std::cout << "bst1 get(4) : " << bst1.get(4)->value() << std::endl;

	bst1.deleteNode(2);
	std::cout << "Deleting node with key = 2" << std::endl;
	std::cout << "bst1 size : " << bst1.size() << std::endl;

	bst1.deleteNode(1);
	std::cout << "Deleting node with key = 1" << std::endl;
	std::cout << "bst1 size : " << bst1.size() << std::endl;

	bst1.deleteNode(3);
	std::cout << "Deleting node with key = 3" << std::endl;
	std::cout << "bst1 size : " << bst1.size() << std::endl;
	std::cout << "bst1 get(0) : " << bst1.get(0)->value() << std::endl;
	std::cout << "bst1 get(2) : " << bst1.get(2)->value() << std::endl;
	std::cout << "bst1 get(4) : " << bst1.get(4)->value() << std::endl;

	return 0;
}