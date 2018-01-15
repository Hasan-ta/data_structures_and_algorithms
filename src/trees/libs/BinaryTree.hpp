#ifndef TREES_LIBS_BINARYTREE_HPP
#define TREES_LIBS_BINARYTREE_HPP

#include <iostream>
template <class T> class BinaryTree{
	public:
		BinaryTree(const T& value);

		void insertLeft(const T& vlaue);

		void insertRight(const T& value);

		T getRootValue(); 

		void setRootValue(const T& value);

		BinaryTree* getLeftChild();

		BinaryTree* getRightChild();

	private:
		T key_ = T();
		BinaryTree* leftChild_ = nullptr;
		BinaryTree* rightChild_ = nullptr;
};

template <class T> void preorder(BinaryTree<T>& tree);
template <class T> void postorder(BinaryTree<T>& tree);

#include "BinaryTreeImpl.hpp"
#endif