#ifndef LINKED_LISTS_LIBS_SINGLYLINKEDLISTImpl_HPP
#define LINKED_LISTS_LIBS_SINGLYLINKEDLISTImpl_HPP

#include <iostream>
// template <class T> typename SinglyLinkedList<T>::Node::Node(const T& element, T* nextPointer)
// {
// 	element_ = element;
// 	nextPointer_ = std::shared_ptr<T>(nextPointer);
// }

// template <class T> typename SinglyLinkedList<T>::Node::Node(const T& element, std::shared_ptr<T> nextPointer)
// {
// 	element_ = element;
// 	nextPointer_ = nextPointer;
// }

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
		tail_ = head_;
	}
	else
	{
		std::shared_ptr<Node> newNode(new Node());
		newNode->element_ = value;
		newNode->nextPointer_ = nullptr;
		tail_->nextPointer_ = newNode;
		tail_ = newNode;
	}
	numOfElements_++;
}

template <class T> bool SinglyLinkedList<T>::isEmpty()
{
	return numOfElements_ == 0;
}

template <class T> void SinglyLinkedList<T>::print()
{
	std::shared_ptr<Node> it = head_;
	while(it != tail_)
	{
		std::cout << it->element_ << std::endl;
		it = it->nextPointer_;
	}
	std::cout << it->element_ << std::endl;
}

#endif