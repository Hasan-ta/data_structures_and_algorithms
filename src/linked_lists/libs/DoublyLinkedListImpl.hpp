#ifndef LINKED_LISTS_LIBS_DOUBLYLINKEDLISTIMPL_HPP
#define LINKED_LISTS_LIBS_DOUBLYLINKEDLISTIMPL_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

template <class T> DoublyLinkedList<T>::Node::Node(const T& value, Node* prev, Node* next)
	: element_(value), prev_(prev), next_(next){}

template <class T> DoublyLinkedList<T>::DoublyLinkedList()
{
	head_ = new Node();
	tail_ = new Node();
	head_->next_ = tail_;
	tail_->prev_ = head_;
}

template <class T> DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node* it = tail_;
	while(it != head_)
	{
		Node* prevNode = it->prev_;
		delete it;
		it = prevNode;
	}
	delete head_;
}

template <class T> void DoublyLinkedList<T>::append(const T& value)
{
	if(isEmpty())
	{
		Node* newNode = new Node(value, head_, tail_);
		head_->next_ = newNode;
		tail_->prev_ = newNode;
	}
	else
	{
		Node* lastNode = tail_->prev_;
		Node* newNode = new Node(value, lastNode, tail_);
		lastNode->next_ = newNode;
		tail_->prev_ = newNode;
	}
	numOfElements_++;
}

template <class T> void DoublyLinkedList<T>::push(const T& value)
{
	Node* firstNode = head_->next_;
	Node* newNode = new Node(value, head_, firstNode);
	head_->next_ = newNode;
	firstNode->prev_ = newNode;
	numOfElements_++;
}

template <class T> T DoublyLinkedList<T>::pop()
{
	if (isEmpty())
		throw std::runtime_error("[DoublyLinkedList]: Trying to pop an empty list");
	else
	{
		Node* nodeToDelete = tail_->prev_;
		T ret = nodeToDelete->element_;
		tail_->prev_ = nodeToDelete->prev_;
		nodeToDelete->prev_->next_ = tail_;
		delete nodeToDelete;
		numOfElements_--;
		return ret;
	}
}

template <class T> typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::traverseList(const uint32_t& index)
{
	Node* it;
	bool incremental;
	int i;
	if(index < numOfElements_/2){it = head_->next_; incremental = true; i = 0;}
	else { it = tail_->prev_; incremental = false; i = numOfElements_-1;}

	while(i != index)
	{
		if(incremental)
		{
			it = it->next_;
			i++;
		}
		else
		{
			it = it->prev_;
			i--;
		}
	}

	return it;
}

template <class T> T& DoublyLinkedList<T>::operator[](const uint32_t& index)
{
	if(index >= numOfElements_)
	{
		std::stringstream ss;
		ss << "[DoublyLinkedList]: Trying to access out of range element. List size: " << numOfElements_ << std::endl;
		throw std::runtime_error(ss.str());
	}
	else
	{
		Node* temp = traverseList(index);
		return temp->element_;
	}
}

template <class T> void DoublyLinkedList<T>::remove(const uint32_t& index)
{
	if(index >= numOfElements_)
	{
		std::stringstream ss;
		ss << "[DoublyLinkedList]: Trying to remove out of range element. List size: " << numOfElements_ << std::endl;
		throw std::runtime_error(ss.str());
	}
	else
	{
		Node* toDelete = traverseList(index);
		Node* prevNode = toDelete->prev_;
		Node* nextNode = toDelete->next_;
		prevNode->next_ = nextNode;
		nextNode->prev_ = prevNode;
		numOfElements_--;
		delete toDelete;
	}
}

template <class T> void DoublyLinkedList<T>::insert(const uint32_t& index, const T& value)
{
	if(index == numOfElements_)
		append(value);
	else if (index == 0)
		push(value);
	else if (index > numOfElements_)
	{
		std::stringstream ss;
		ss << "[Doubly Linked List]: Out of range insertion. List size: " << numOfElements_ << std::endl;
		throw (ss.str());
	}
	else
	{
		Node* prevNode = traverseList(index-1);
		Node* nextNode = prevNode->next_;
		Node* newNode = new Node(value, prevNode, nextNode);
		prevNode->next_ = newNode;
		nextNode->prev_ = newNode;
		numOfElements_++;
	}
}

template <class T> uint32_t DoublyLinkedList<T>::size()
{
	return numOfElements_;
}

template <class T> bool DoublyLinkedList<T>::isEmpty()
{
	return numOfElements_ == 0;
}

template <class T> void DoublyLinkedList<T>::print()
{
	Node* it = head_->next_;
	while(it != tail_)
	{
		std::cout << it->element_ << std::endl;
		it = it->next_;
	}
	std::cout << "\n*************************************" << std::endl;
}


#endif