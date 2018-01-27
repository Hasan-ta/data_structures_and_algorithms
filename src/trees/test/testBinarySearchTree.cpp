#include "BinarySearchTree.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	BinarySearchTree<int, char> bst1;

	bst1.put(0,'a');
	bst1.put(1,'b');
	bst1.put(2,'c');

	return 0;
}