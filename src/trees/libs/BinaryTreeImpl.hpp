#ifndef TREES_LIBS_BINARYTREEIMPL_HPP
#define TREES_LIBS_BINARYTREEIMPL_HPP

template <class T> BinaryTree<T>::BinaryTree(const T& value)
{
	key_ = value;
}

template <class T> void BinaryTree<T>::insertLeft(const T& value)
{
	if(leftChild_ == nullptr)
	{
		leftChild_ = new BinaryTree(value);
	}
	else
	{
		BinaryTree* t = new BinaryTree(value);
		t->leftChild_ = leftChild_;
		leftChild_ = t;
	}

}

template <class T> void BinaryTree<T>::insertRight(const T& value)
{
	if(rightChild_ == nullptr)
	{
		rightChild_ = new BinaryTree(value);
	}
	else
	{
		BinaryTree* t = new BinaryTree(value);
		t->rightChild_ = rightChild_;
		rightChild_ = t;
	}
}

template <class T> T BinaryTree<T>::getRootValue()
{
	return key_;
}

template <class T> void BinaryTree<T>::setRootValue(const T& value)
{
	key_ = value;
}

template <class T> BinaryTree<T>* BinaryTree<T>::getLeftChild()
{
	return leftChild_;
}

template <class T> BinaryTree<T>* BinaryTree<T>::getRightChild()
{
	return rightChild_;
}

template <class T> void preorder(BinaryTree<T>& tree)
{
	std::cout << tree.getRootValue() << std::endl;
	if(tree.getLeftChild() != nullptr)
		preorder(*tree.getLeftChild());
	if(tree.getRightChild() != nullptr)
		preorder(*tree.getRightChild());
}

template <class T> void postorder(BinaryTree<T>& tree)
{
	if(tree.getLeftChild() != nullptr)
		postorder(*tree.getLeftChild());
	if(tree.getRightChild() != nullptr)
		postorder(*tree.getRightChild());
	std::cout << tree.getRootValue() << std::endl;
}

template <class T> void inorder(BinaryTree<T>& tree)
{
	if(tree.getLeftChild() != nullptr)
		inorder(*tree.getLeftChild());
	std::cout << tree.getRootValue() << std::endl;
	if(tree.getRightChild() != nullptr)
		inorder(*tree.getRightChild());
}

#endif