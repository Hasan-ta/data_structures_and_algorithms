#ifndef TREES_LIBS_BINARYSEARCHTREE_HPP
#define TREES_LIBS_BINARYSEARCHTREE_HPP

#include <stdint.h>


template <class keyType, class valueType> class BinarySearchTree{
public:
	class Node{
	public:
		keyType key_;
		valueType value_;
		Node* rightChild_ = nullptr;
		Node* leftChild_ = nullptr;
		Node* parent_ = nullptr;

		Node(const keyType& key, const valueType& value)
		{
			key_ = key;
			value_ = valueType(value);
		}
		~Node()
		{
			delete rightChild_;
			delete leftChild_;
		}
		void nullifyNode()
		{
			leftChild_ = rightChild_ = parent_ = nullptr;
		}
		bool isRoot()
		{
			bool ret = false;
			parent_ == nullptr ? ret = true : ret = false;
			return ret;
		}
		bool isLeaf()
		{
			bool ret = false;
			rightChild_ == nullptr && leftChild_ == nullptr ? ret = true : ret = false;
			return ret;
		}
		bool hasLeftChild()
		{
			bool ret = false;
			leftChild_ != nullptr ? ret = true : ret = false;
			return ret;
		}
		bool hasRightChild()
		{
			bool ret = false;
			rightChild_ != nullptr ? ret = true : ret = false;
			return ret;
		}
		bool isLeftChild()
		{
			if(parent_ == nullptr)
				return false;
			else if (parent_->leftChild_ == this)
				return true;
			else
				return false;
		}
		bool isRightChild()
		{
			if(parent_ == nullptr)
				return false;
			else if (parent_->rightChild_ == this)
				return true;
			else
				return false;
		}
		const valueType value() const {return value_;}
		valueType value() {return value_;}
	};

public:
	BinarySearchTree();

	BinarySearchTree(const keyType& key, const valueType& value);

	virtual ~BinarySearchTree();

	uint32_t size();
	const uint32_t size() const;

	void put(const keyType& key, const valueType& value);

	Node* const get(const keyType& keyIn);

	void deleteNode(const keyType& keyIn);

private:

	Node* root_ = nullptr;

	uint32_t size_ = 0;

	bool put_(const keyType& key, const valueType& value, Node* begNode);

	Node* get_(const keyType& keyIn, Node* begNode);

	void remove(Node* nodeToDelete);

	Node* findSuccessor(Node* currentNode);

	Node* findMin(Node* currentNode);

	void spliceOut(Node* currentNode);

};

#include "BinarySearchTreeImpl.hpp"
#endif