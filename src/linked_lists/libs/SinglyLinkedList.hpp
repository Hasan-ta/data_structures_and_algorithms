#ifndef LINKED_LISTS_LIBS_SINGLYLINKEDLIST_HPP
#define LINKED_LISTS_LIBS_SINGLYLINKEDLIST_HPP

#include <memory>

template <class T> class SinglyLinkedList{
private:

	class Node{
	public:

		Node(){}

		Node(const T& element, Node* nextPointer);

		Node* nextPointer_ = nullptr;
		T element_;
	};

public:
	SinglyLinkedList();

	void append(const T& value);

	T pop();

	T& operator[](const uint32_t& index);

	void remove(const uint32_t& index);

	void insert(const uint32_t& index, const T& value);

	uint32_t size();

	bool isEmpty();

	void print();

private:

	Node* head_;

	Node* tail_;

	uint32_t numOfElements_ = 0;

	Node* traverseList(const uint32_t& index);	
};

#include "SinglyLinkedListImpl.hpp"

#endif