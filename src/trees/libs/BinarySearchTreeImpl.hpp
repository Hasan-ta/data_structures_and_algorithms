#ifndef TREES_LIBS_BINARYSEARCHTREEIMPL_HPP
#define TREES_LIBS_BINARYSEARCHTREEIMPL_HPP

template <class keyType, class vlaueType> BinarySearchTree<keyType, vlaueType>::BinarySearchTree()
{
	root_ = nullptr;
}

template <class keyType, class vlaueType> BinarySearchTree<keyType, vlaueType>::BinarySearchTree()
{
	root_ = nullptr;
}

template <class keyType, class vlaueType> uint32_t BinarySearchTree<keyType, vlaueType>::size()
{
	return size_;
}

template <class keyType, class vlaueType> void BinarySearchTree<keyType, vlaueType>::put(const keyType& key, const vlaueType& value)
{
	if(root_ == nullptr)
		root_ = new Node(key,value);
	else
		put_(key, value, root_);
}

template <class keyType, class vlaueType> void BinarySearchTree<keyType, vlaueType>::put_(const keyType& key, const vlaueType& value, Node* begNode)
{
	Node* nextNode;
	key < begNode->key_ ? nextNode = begNode->leftChild_ : begNode->rightChild_;

	if(nextNode == nullptr)
		nextNode = new Node(key, value);
	else
		put_(key, value, nextNode);
}

#endif