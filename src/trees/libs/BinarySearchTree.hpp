#ifndef TREES_LIBS_BINARYSEARCHTREE_HPP
#define TREES_LIBS_BINARYSEARCHTREE_HPP

#include <stdint.h>


template <class keyType, class valueType> class BinarySearchTree{
private:
	// class Node{
	// public:
	// 	keyType key_;
	// 	valueType value_;
	// 	Node* rightChild_ = nullptr;
	// 	Node* leftChild_ = nullptr;

	// 	Node(const keyType& key, const valueType& value)
	// 	{
	// 		key_ = key;
	// 		value_ = value;
	// 	}
	// };

public:
	BinarySearchTree();

	BinarySearchTree(const keyType& key, const valueType& value);

	virtual ~BinarySearchTree();

	uint32_t size();

	void put(const keyType& key, const valueType& value);

	const BinarySearchTree* get(const keyType& keyIn);

	const valueType value() const;
	valueType value();

private:

	keyType key_;
	valueType value_;
	BinarySearchTree* rightChild_ = nullptr;
	BinarySearchTree* leftChild_ = nullptr;

	// Node* root_ = nullptr;

	uint32_t size_ = 0;

	bool put_(const keyType& key, const valueType& value, BinarySearchTree* begNode);
	const BinarySearchTree* get_(const keyType& keyIn, BinarySearchTree* begNode);
};

#include "BinarySearchTreeImpl.hpp"
#endif