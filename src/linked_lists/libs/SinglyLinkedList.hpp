#ifndef LINKED_LISTS_LIBS_SINGLYLINKEDLIST_HPP
#define LINKED_LISTS_LIBS_SINGLYLINKEDLIST_HPP

#include <memory>

template <class T> class SinglyLinkedList{
private:
	class Node{
	public:
		Node(const T& element, T* nextPointer);

		Node(const T& element, std::unique_ptr<T> nextPointer);

		void setNextPointer(T* nextNode);

		void setElement(const T& value);

	private:
		std::unique_ptr<T> nextPointer_;
		T element_;
	};

public:
	SinglyLinkedList();

	void append(const T& value);

	T pop();

	T operator[](const uint32_t& index);

	void remove(const uint32_t& index);

private:

	std::share_ptr<T> head_;

	uint32_t numberOfElements_ = 0;
	
};


#endif 