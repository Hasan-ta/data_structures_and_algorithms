#ifndef LINKED_LISTS_LIBS_SINGLYLINKEDLIST_HPP
#define LINKED_LISTS_LIBS_SINGLYLINKEDLIST_HPP

#include <cstdint>

template <class T> class SinglyLinkedList{
private:

	class Node{
	public:

		/**
		 * @brief      Default Constructor
		 */
		Node(){}

		/**
		 * @brief      Constructs a node with element as a value and nextPointer as the next node pointer
		 *
		 * @param[in]  element      The element
		 * @param      nextPointer  The next pointer
		 */
		Node(const T& element, Node* nextPointer);

		Node* nextPointer_ = nullptr;
		T element_;
	};

public:

	/**
	 * @brief      Default Constructor
	 */
	SinglyLinkedList();

	/**
	 * @brief      Destroys the object.
	 */
	virtual ~SinglyLinkedList();

	/**
	 * @brief      Appends nodes to the end of the list
	 *
	 * @param[in]  value  Value of element to append
	 */
	void append(const T& value);

	/**
	 * @brief      Inserts nodes at the head of list
	 *
	 * @param[in]  value  Value of element to append
	 */
	void push(const T& value);

	/**
	 * @brief      Extracts the last node in the list
	 *
	 * @return     return a copy of the element in the last node
	 */
	T pop();

	/**
	 * @brief      Access node at index
	 *
	 * @param[in]  index  The index
	 *
	 * @return     Reference to the node at index
	 */
	T& operator[](const uint32_t& index);

	/**
	 * @brief      Remove node located at index
	 *
	 * @param[in]  index  The index
	 */
	void remove(const uint32_t& index);

	/**
	 * @brief      Insert node at index
	 *
	 * @param[in]  index  The index
	 * @param[in]  value  The value
	 */
	void insert(const uint32_t& index, const T& value);

	/**
	 * @brief      Return the number of nodes in the list
	 *
	 * @return     number of nodes
	 */
	uint32_t size();

	/**
	 * @brief      Determines if empty.
	 *
	 * @return     True if empty, False otherwise.
	 */
	bool isEmpty();

	void print();

	void reverse();

private:

	Node* head_;

	Node* tail_;

	uint32_t numOfElements_ = 0;

	Node* traverseList(const uint32_t& index);	
};

#include "SinglyLinkedListImpl.hpp"

#endif