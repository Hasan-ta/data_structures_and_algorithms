#ifndef STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUE_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUE_HPP

#include <memory>

template <class T> class Dequeue{
public:

	/**
	 * @brief      Default Constructor
	 */
	Dequeue();

	/**
	 * @brief      Add element at the front end of queue
	 *
	 * @param[in]  element  The element
	 */
	void addFront(const T& element);

	/**
	 * @brief      Add element at the rear end of the queue
	 *
	 * @param[in]  element  The element
	 */
	void addRear(const T& element);

	/**
	 * @brief      Removes an element from the front end
	 *
	 * @return     A copy of the element
	 */
	T removeFront();

	/**
	 * @brief      Removes an element from the rear end
	 *
	 * @return     A copy of the element
	 */
	T removeRear();

	/**
	 * @brief      Returns number of elements in queue
	 *
	 * @return     number of elements in queue.
	 */
	uint32_t size();

	/**
	 * @brief      Determines if empty.
	 *
	 * @return     True if empty, False otherwise.
	 */
	bool isEmpty();

private:

	std::shared_ptr<T> dequeuePtr_;

	uint32_t halfWayPointer_;

	uint32_t frontPointer_;

	uint32_t rearPointer_;

	uint32_t numOfElements_;

	uint32_t capacity_ = 2;

	void resize(const uint32_t& newSize);

};

#include "DequeueImpl.hpp"

#endif