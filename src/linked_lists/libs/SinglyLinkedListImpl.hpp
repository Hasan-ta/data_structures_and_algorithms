#ifndef LINKED_LISTS_LIBS_SINGLYLINKEDLISTIMPL_HPP
#define LINKED_LISTS_LIBS_SINGLYLINKEDLISTIMPL_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Stack.hpp"

template <class T> SinglyLinkedList<T>::Node::Node(const T& element, Node* nextPointer)
{
	element_ = element;
	nextPointer_ = nextPointer;
}

template <class T> SinglyLinkedList<T>::SinglyLinkedList()
{
	head_ = new Node();
	tail_ = nullptr;
}

template <class T> SinglyLinkedList<T>::~SinglyLinkedList()
{
	Node* it = head_;
	while(it != tail_)
	{
		Node* nextNode = it->nextPointer_;
		delete it;
		it = nextNode;
	}
	delete tail_;
}

template <class T> void SinglyLinkedList<T>::append(const T& value)
{
	if(isEmpty())
	{
		head_->element_ = value;
		head_->nextPointer_ = nullptr;
		tail_ = head_;
	}
	else
	{
		Node* newNode = new Node(value, nullptr);
		tail_->nextPointer_ = newNode;
		tail_ = newNode;
	}
	numOfElements_++;
}

template <class T> void SinglyLinkedList<T>::push(const T& value)
{
	if(isEmpty())
	{
		head_->element_ = value;
		head_->nextPointer_ = nullptr;
		tail_ = head_;
	}
	else
	{
		Node* newNode = new Node(value, nullptr);
		newNode->nextPointer_ = head_;
		head_ = newNode;
	}
	numOfElements_++;
}

template <class T> T SinglyLinkedList<T>::pop()
{
	T ret = tail_->element_;
	delete tail_;
	if(numOfElements_ == 1)
		tail_ = head_;
	else if (numOfElements_ == 0)
		throw std::runtime_error("Trying to pop an empty list");
	else
		tail_ = traverseList(numOfElements_-2);
	numOfElements_--;
	return ret;
}

template <class T> typename SinglyLinkedList<T>::Node* SinglyLinkedList<T>::traverseList(const uint32_t& index)
{
	Node* it = head_;
	int i = 0;
	while(i != index)
	{
		it = it->nextPointer_;
		i++;
	}

	return it;
}

template <class T> T& SinglyLinkedList<T>::operator[](const uint32_t& index)
{
	Node* temp = traverseList(index);
	return temp->element_;
}

template <class T> void SinglyLinkedList<T>::remove(const uint32_t& index)
{
	Node* temp = traverseList(index-1);
	Node* toDelete = temp->nextPointer_;
	temp->nextPointer_ = toDelete->nextPointer_;
	numOfElements_--;
	delete toDelete;
}

template <class T> void SinglyLinkedList<T>::insert(const uint32_t& index, const T& value)
{
	if(index == numOfElements_)
		append(value);
	else if (index == 0)
		push(value);
	else if (index > numOfElements_)
	{
		std::stringstream ss;
		ss << "[Singly Linked List]: Out of range insertion. List size: " << numOfElements_ << std::endl;
		throw std::runtime_error(ss.str());
	}
	else
	{
		Node* prevNode = traverseList(index-1);
		Node* nextNode = prevNode->nextPointer_;
		Node* newNode = new Node(value, nextNode);
		prevNode->nextPointer_ = newNode;
		numOfElements_++;
	}
}

template <class T> uint32_t SinglyLinkedList<T>::size()
{
	return numOfElements_;
}

template <class T> bool SinglyLinkedList<T>::isEmpty()
{
	return numOfElements_ == 0;
}

template <class T> void SinglyLinkedList<T>::print()
{
	Node* it = head_;
	while(it != tail_)
	{
		std::cout << it->element_ << std::endl;
		it = it->nextPointer_;
	}
	std::cout << it->element_ << std::endl;
	std::cout << "*************************************" << std::endl;
}

template <class T> void SinglyLinkedList<T>::reverse()
{
	// Fill the stack
	// Stack<Node*> nodePointers;

	// Node* it = head_;

	// while(it != tail_)
	// {
	// 	nodePointers.push(it);
	// 	it = it->nextPointer_;
	// }

	// // Reverse order
	// Node* newHead = it;
	// Node* it_1;
	// while(it_1 != head_)
	// {
	// 	it_1 = nodePointers.pop();
	// 	it->nextPointer_ = it_1;
	// 	it = it_1;
	// }
	// it_1->nextPointer_ = nullptr;
	// tail_ = it_1;
	// head_ = newHead;
	// 
	
	Node* it = head_;
	Node* it_1 = it->nextPointer_;
	Node* it_2 = it_1->nextPointer_;

	Node* newTail = it;
	while(it_2 != tail_)
	{
		it_1->nextPointer_ = it;
		it = it_1;
		it_1 = it_2;
		it_2 = it_1->nextPointer_;
	}
	it_2->nextPointer_ = it_1;
	it_1->nextPointer_ = it;
	tail_ = newTail;
	head_ = it_2;
}

#endif