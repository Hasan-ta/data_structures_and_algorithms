#ifndef LINKED_LISTS_LIBS_SINGLYLINKEDLIST_HPP
#define LINKED_LISTS_LIBS_SINGLYLINKEDLIST_HPP

#include <memory>

template <class T> class SinglyLinkedList{
private:
	class Node{
	public:
		// Node(const T& element, T* nextPointer);

		// Node(const T& element, std::shared_ptr<Node> nextPointer);

		// void setNextPointer(T* nextNode);

		// void setElement(const T& value);

	// TODO Change to private
	public:
		std::shared_ptr<Node> nextPointer_ = nullptr;
		T element_;
	};

public:
	SinglyLinkedList();

	void append(const T& value);

	T pop();

	T operator[](const uint32_t& index);

	void remove(const uint32_t& index);

	bool isEmpty();

	void print();

private:

	std::shared_ptr<Node> head_;

	std::shared_ptr<Node> tail_;

	uint32_t numOfElements_ = 0;
	
};

#include "SinglyLinkedListImpl.hpp"

#endif 