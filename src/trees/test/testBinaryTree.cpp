#include "BinaryTree.hpp"

int main(int argc, char** argv)
{
	BinaryTree<int> tree1(0);

 	// Create the following tree:
 			// 	    0
 			//    |   |
 			//   |     |
 			//   1	    2
 			//  | |    | |
 			// |   |  |   |
 			// 3   4  5   6
 	
	tree1.insertLeft(3);
	tree1.insertLeft(1);
	tree1.getLeftChild()->insertRight(4);
	tree1.insertRight(6);
	tree1.insertRight(2);
	tree1.getRightChild()->insertLeft(5);

	std::cout << "preorder: " << std::endl;
	preorder(tree1);

	std::cout << "postorder: " << std::endl;
	postorder(tree1);

	std::cout << "inorder: " << std::endl;
	inorder(tree1);
}