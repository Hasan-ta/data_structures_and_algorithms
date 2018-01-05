#ifndef LINKED_LISTS_LIBS_SINGLYLINKEDLISTImpl_HPP
#define LINKED_LISTS_LIBS_SINGLYLINKEDLISTImpl_HPP

#include <iostream>
#include <exception>

template <class T> SinglyLinkedList<T>::Node::Node(const T& element, Node* nextPointer)
{
	element_ = element;
	nextPointer_ = std::unique_ptr<Node>(nextPointer);
}

template <class T> SinglyLinkedList<T>::Node::Node(const T& element, std::unique_ptr<Node> nextPointer)
{
	element_ = element;
	nextPointer_ = nextPointer;
}

template <class T> SinglyLinkedList<T>::SinglyLinkedList()
{
	head_ = std::shared_ptr<Node>(new SinglyLinkedList<T>::Node());
	tail_ = nullptr;
}

template <class T> void SinglyLinkedList<T>::append(const T& value)
{
	if(isEmpty())
	{
		head_->element_ = value;
		head_->nextPointer_ = nullptr;
		tail_ = std::unique_ptr<Node>(head_.get());
	}
	else
	{
		std::unique_ptr<Node> newNode(new Node(value, nullptr));
		tail_ = std::move(newNode);
	}
	numOfElements_++;
}

template <class T> bool SinglyLinkedList<T>::isEmpty()
{
	return numOfElements_ == 0;
}

template <class T> T SinglyLinkedList<T>::pop()
{
	T ret = tail_->element_;
	tail_->nextPointer_ = nullptr;
	if(numOfElements_ == 2)
		tail_ = head_->nextPointer_;
	else if (numOfElements_ == 1)
		tail_ = head_;
	else if (numOfElements_ == 0)
		throw std::runtime_error("Trying to pop an empty list");
	else
	{	
		Node temp = traverseList(numOfElements_-3);
		tail_ = temp.nextPointer_;
	}
	numOfElements_--;
	return ret;
}

template <class T> typename SinglyLinkedList<T>::Node SinglyLinkedList<T>::traverseList(const uint32_t& index)
{
	std::shared_ptr<Node> it = head_;
	int i = 0;
	while(i != index)
	{
		it = it->nextPointer_;
		i++;
	}

	return *it;
}

template <class T> T SinglyLinkedList<T>::operator[](const uint32_t& index)
{
	Node temp = traverseList(index);
	return temp->element_;
}

template <class T> void SinglyLinkedList<T>::print()
{
	std::unique_ptr<Node> it = head_.get();
	while(it != tail_)
	{
		std::cout << it->element_ << std::endl;
		it = it->nextPointer_;
	}
	std::cout << it->element_ << std::endl;
}

#endif