#ifndef TREES_LIBS_BINARYSEARCHTREEIMPL_HPP
#define TREES_LIBS_BINARYSEARCHTREEIMPL_HPP

template <class keyType, class vlaueType> BinarySearchTree<keyType, vlaueType>::BinarySearchTree()
{
	// root_ = nullptr;
}

template <class keyType, class vlaueType> BinarySearchTree<keyType, vlaueType>::BinarySearchTree(const keyType& key, const vlaueType& value)
{
	root_ = new Node(key, value);
}

template <class keyType, class vlaueType> BinarySearchTree<keyType, vlaueType>::~BinarySearchTree()
{
	delete root_;
}

template <class keyType, class vlaueType> uint32_t BinarySearchTree<keyType, vlaueType>::size()
{
	return size_;
}

template <class keyType, class vlaueType> void BinarySearchTree<keyType, vlaueType>::put(const keyType& key, const vlaueType& value)
{
	// if(root_ == nullptr)
	if(size_ == 0)
	{
		root_ = new Node(key,value);
		size_++;
	}
	else
		if(put_(key, value, root_)) {size_++;}
}

template <class keyType, class vlaueType> bool BinarySearchTree<keyType, vlaueType>::put_(const keyType& key, const vlaueType& value, Node* begNode)
{
	Node* nextNode;
	if(key < begNode->key_)
	{
		nextNode = begNode->leftChild_;
		if(nextNode == nullptr)
		{
			begNode->leftChild_ = new Node(key, value);
			begNode->leftChild_->parent_ = begNode;
		}
		else
			return put_(key, value, begNode->leftChild_);
	}
	else if (key > begNode->key_)
	{
		nextNode = begNode->rightChild_;
		if(nextNode == nullptr)
		{
			begNode->rightChild_ = new Node(key, value);
			begNode->rightChild_->parent_ = begNode;
		}
		else
			return put_(key, value, begNode->rightChild_);
	}
	else
	{
		begNode->key_ = key; 
		begNode->value_ = value;
		return false;
	}
}

template <class keyType, class valueType> typename BinarySearchTree<keyType,valueType>::Node* const BinarySearchTree<keyType, valueType>::get(const keyType& keyIn)
{
	if(root_->key_ == keyIn)
		return root_;
	else
		return get_(keyIn, root_);
}

template <class keyType, class valueType> typename BinarySearchTree<keyType,valueType>::Node* const BinarySearchTree<keyType, valueType>::get_(const keyType& keyIn, Node* begNode)
{
	if(keyIn < begNode->key_)
	{
		if(begNode->leftChild_ == nullptr)
			return nullptr;
		else
		{
			if(begNode->leftChild_->key_ == keyIn)
				return begNode->leftChild_;	
			else
				return get_(keyIn, begNode->leftChild_);
		}
	}
	else
	{
		if(begNode->rightChild_ == nullptr)
			return nullptr;
		else
		{
			if(begNode->rightChild_->key_ == keyIn)
				return begNode->rightChild_;	
			else
				return get_(keyIn, begNode->rightChild_);
		}
	}
}

#endif