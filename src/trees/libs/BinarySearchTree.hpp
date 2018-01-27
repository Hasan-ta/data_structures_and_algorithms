#ifndef TREES_LIBS_BINARYSEARCHTREE_HPP
#define TREES_LIBS_BINARYSEARCHTREE_HPP

#include <stdint.h>
template <class keyType, class valueType> class BinarySearchTree{
private:
	class Node{
	public:
		keyType key_;
		valueType value_;
		Node* rightChild_ = nullptr;
		Node* leftChild_ = nullptr;

		Node(const keyType& key, const valueType& value)
		{
			key_ = key;
			value_ = value;
		}
	};

public:
	BinarySearchTree();

	virtual ~BinarySearchTree(){};

	uint32_t size();

	void put(const keyType& key, const valueType& value);

private:

	Node* root_ = nullptr;

	uint32_t size_ = 0;

	void put_(const keyType& key, const valueType& value, Node* begNode);
};

#include "BinarySearchTreeImpl.hpp"
#endif