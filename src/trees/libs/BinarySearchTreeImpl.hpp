#ifndef TREES_LIBS_BINARYSEARCHTREEIMPL_HPP
#define TREES_LIBS_BINARYSEARCHTREEIMPL_HPP

template <class keyType, class vlaueType> BinarySearchTree<keyType, vlaueType>::BinarySearchTree()
{
	// root_ = nullptr;
}

template <class keyType, class vlaueType> BinarySearchTree<keyType, vlaueType>::BinarySearchTree(const keyType& key, const vlaueType& value)
{
	key_ = key;
	value_ = value;
}

template <class keyType, class vlaueType> BinarySearchTree<keyType, vlaueType>::~BinarySearchTree()
{
	delete leftChild_;
	delete rightChild_;
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
		key_ = key; value_ = value; size_++;
	}
	else
		if(put_(key, value, this)) {size_++;}
}

template <class keyType, class vlaueType> bool BinarySearchTree<keyType, vlaueType>::put_(const keyType& key, const vlaueType& value, BinarySearchTree* begNode)
{
	BinarySearchTree* nextNode;
	if(key < begNode->key_)
	{
		nextNode = begNode->leftChild_;
		if(nextNode == nullptr)
			begNode->leftChild_ = new BinarySearchTree(key, value);
		else
			return put_(key, value, begNode->leftChild_);
	}
	else if (key > begNode->key_)
	{
		nextNode = begNode->rightChild_;
		if(nextNode == nullptr)
			begNode->rightChild_ = new BinarySearchTree(key, value);
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

template <class keyType, class valueType> const BinarySearchTree<keyType, valueType>* BinarySearchTree<keyType, valueType>::get(const keyType& keyIn)
{
	if(key_ == keyIn)
		return this;
	else
		return get_(keyIn, this);
}

template <class keyType, class valueType> const BinarySearchTree<keyType, valueType>* BinarySearchTree<keyType, valueType>::get_(const keyType& keyIn, BinarySearchTree* begNode)
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

template <class keyType, class valueType> valueType BinarySearchTree<keyType, valueType>::value()
{
	return value_;
}

template <class keyType, class valueType> const valueType BinarySearchTree<keyType, valueType>::value() const
{
	return value_;
}

#endif