#ifndef STACKS_QUEUES_DEQUEUES_LIBS_STACK_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_STACK_HPP

#include <memory>

template <class T> class Stack{
public:

	/**
	 * @brief      Default Constructor
	 */
	Stack();

	/**
	 * @brief      Push an item to the stack
	 *
	 * @param[in]  item  The item
	 *
	 * @return     is the push successful
	 */
	bool push(const T& item);

	/**
	 * @brief      pop an item from the stack
	 *
	 * @return     reference to the item
	 */
	T pop();

	/**
	 * @brief      return a copy of the stack head
	 *
	 * @return     value at stack head
	 */
	T peek();

	/**
	 * @brief      Number of elements in the stack
	 *
	 * @return     Number of elements in the stack
	 */
	uint32_t size();

	/**
	 * @brief      check if stack is empty
	 *
	 * @return     True if empty, False otherwise.
	 */
	bool isEmpty();

private:

	T* stackHead_;

	std::shared_ptr<T> stackBase_;

	uint32_t capacity_ = 1;

	uint32_t numOfItems_ = 0;

	/**
	 * @brief      resize the stack
	 *
	 * @param[in]  newSize  The new size
	 */
	void resize(const int& newSize);

};

#include "StackImpl.hpp"

#endif 