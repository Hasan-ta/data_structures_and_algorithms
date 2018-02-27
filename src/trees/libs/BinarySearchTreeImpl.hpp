#ifndef TREES_LIBS_BINARYSEARCHTREEIMPL_HPP
#define TREES_LIBS_BINARYSEARCHTREEIMPL_HPP

#include <stdexcept>

template <class keyType, class valueType> BinarySearchTree<keyType, valueType>::BinarySearchTree()
{
	// root_ = nullptr;
}

template <class keyType, class valueType> BinarySearchTree<keyType, valueType>::BinarySearchTree(const keyType& key, const valueType& value)
{
	root_ = new Node(key, value);
}

template <class keyType, class valueType> BinarySearchTree<keyType, valueType>::~BinarySearchTree()
{
	delete root_;
}

template <class keyType, class valueType> uint32_t BinarySearchTree<keyType, valueType>::size()
{
	return size_;
}

template <class keyType, class valueType> void BinarySearchTree<keyType, valueType>::put(const keyType& key, const valueType& value)
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

template <class keyType, class valueType> bool BinarySearchTree<keyType, valueType>::put_(const keyType& key, const valueType& value, Node* begNode)
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

template <class keyType, class valueType> typename BinarySearchTree<keyType,valueType>::Node* BinarySearchTree<keyType, valueType>::get_(const keyType& keyIn, Node* begNode)
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
	else if (keyIn > begNode->key_)
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
	else
		return begNode;
}

template <class keyType, class valueType> void BinarySearchTree<keyType, valueType>::deleteNode(const keyType& keyIn)
{
	if(size_ == 0)
		throw std::runtime_error("Trying to delete from empty tree");
	else if(size_ == 1 && root_->key_ == keyIn)
	{
		delete root_;
		root_ = nullptr;
		size_ = 0;
	}
	else
	{
		remove(get_(keyIn, root_));
		size_--;
	}

}

template <class keyType, class valueType> void BinarySearchTree<keyType, valueType>::remove(Node* nodeToDelete)
{
	if(nodeToDelete->isLeaf())
	{
		if(nodeToDelete == nodeToDelete->parent_->leftChild_)
			nodeToDelete->parent_->leftChild_ = nullptr;
		else
			nodeToDelete->parent_->rightChild_ = nullptr;
		nodeToDelete->nullifyNode();
		delete nodeToDelete;
	}
	else if(nodeToDelete->hasLeftChild() && nodeToDelete->hasRightChild())
	{
		Node* succ = findSuccessor(nodeToDelete);
		spliceOut(succ);
		succ->parent_ = nodeToDelete->parent_;
		succ->leftChild_ = nodeToDelete->leftChild_;
		succ->rightChild_ = nodeToDelete->rightChild_;

		if(nodeToDelete->isLeftChild())
			succ->parent_->leftChild_ = succ;
		else if (nodeToDelete->isRightChild())
			succ->parent_->rightChild_ = succ;

		nodeToDelete->nullifyNode();
		delete nodeToDelete;
	}
	else
	{
		if(nodeToDelete->hasLeftChild())
		{
			if(nodeToDelete->isLeftChild())
			{
				nodeToDelete->parent_->leftChild_ = nodeToDelete->leftChild_;
				nodeToDelete->leftChild_->parent_ = nodeToDelete->parent_;
				nodeToDelete->nullifyNode();
				delete nodeToDelete;
			}
			else if(nodeToDelete->isRightChild())
			{
				nodeToDelete->parent_->rightChild_ = nodeToDelete->leftChild_;
				nodeToDelete->leftChild_->parent_ = nodeToDelete->parent_;
				nodeToDelete->nullifyNode();
				delete nodeToDelete;
			}
			else
			{
				root_ = nodeToDelete->leftChild_;
				root_->parent_ = nullptr;
				nodeToDelete->nullifyNode();
				delete nodeToDelete;
				// nodeToDelete->key_ = nodeToDelete->leftChild_->key_;
				// nodeToDelete->value_ = nodeToDelete->leftChild_->value_;
				// nodeToDelete->leftChild_ = nodeToDelete->leftChild_->leftChild_;
				// nodeToDelete->rightChild_ = nodeToDelete->leftChild_->rightChild_;
				// nodeToDelete->leftChild_->parent_ = nullptr;
			}
		}
		else if (nodeToDelete->hasRightChild())
		{
			if(nodeToDelete->isLeftChild())
			{
				nodeToDelete->parent_->rightChild_ = nodeToDelete->rightChild_;
				nodeToDelete->rightChild_->parent_ = nodeToDelete->parent_;
				nodeToDelete->nullifyNode();
				delete nodeToDelete;
			}
			else if(nodeToDelete->isRightChild())
			{
				nodeToDelete->parent_->rightChild_ = nodeToDelete->rightChild_;
				nodeToDelete->rightChild_->parent_ = nodeToDelete->parent_;
				nodeToDelete->nullifyNode();
				delete nodeToDelete;
			}
			else
			{
				root_ = nodeToDelete->rightChild_;
				root_->parent_ = nullptr;
				nodeToDelete->nullifyNode();
				delete nodeToDelete;
				// nodeToDelete->key_ = nodeToDelete->rightChild_->key_;
				// nodeToDelete->value_ = nodeToDelete->rightChild_->value_;
				// nodeToDelete->leftChild_ = nodeToDelete->rightChild_->leftChild_;
				// nodeToDelete->rightChild_ = nodeToDelete->rightChild_->rightChild_;
				// nodeToDelete->rightChild_->parent_ = nullptr;
			}
		}
	}
}

template <class keyType, class valueType> typename BinarySearchTree<keyType,valueType>::Node* BinarySearchTree<keyType, valueType>::findSuccessor(Node* currentNode)
{
	Node* succ = nullptr;
	if(currentNode->hasRightChild())
	    succ = findMin(currentNode->rightChild_);
	// else
	// {
	//     if(!currentNode->isRoot())
	//     {
	//         if(currentNode->isLeftChild())
	//             succ = currentNode->parent_;
	//         else
	//         {
	//             currentNode->parent_->rightChild_ = nullptr;
	//             succ = findSuccessor(currentNode->parent_);
	//             currentNode->parent_->rightChild_ = currentNode;
	//         }
	//     }
	// }
	return succ;
}

template <class keyType, class valueType> typename BinarySearchTree<keyType,valueType>::Node* BinarySearchTree<keyType, valueType>::findMin(Node* currentNode)
{
	Node* temp = currentNode;
	while(temp->hasLeftChild())
	   temp = temp->leftChild_;
	return temp;
}

template <class keyType, class valueType> void BinarySearchTree<keyType, valueType>::spliceOut(Node* currentNode)
{
	if(currentNode->isLeaf())
	{
		if(currentNode->isLeftChild())
			currentNode->parent_->leftChild_ = nullptr;
		else
			currentNode->parent_->rightChild_ = nullptr;
	}

	else if (currentNode->hasLeftChild() || currentNode->hasRightChild())
	{
		if(currentNode->hasLeftChild())
		{
			if(currentNode->isLeftChild())
				currentNode->parent_->leftChild_ = currentNode->leftChild_;
			else
				currentNode->parent_->rightChild_ = currentNode->leftChild_;
			
			currentNode->leftChild_->parent_ = currentNode->parent_;
		}

		else
		{
			if(currentNode->isLeftChild())
				currentNode->parent_->leftChild_ = currentNode->rightChild_;
			else
				currentNode->parent_->rightChild_ = currentNode->rightChild_;

			currentNode->rightChild_->parent_ = currentNode->parent_;
		}
	}

	// currentNode->nullifyNode();
	// delete currentNode;
}

#endif