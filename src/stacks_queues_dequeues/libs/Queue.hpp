#ifndef STACKS_QUEUES_DEQUEUES_LIBS_QUEUE_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_QUEUE_HPP

#include <memory>

template <class T> class Queue{
public:

	/**
	 * @brief      Default Constructor
	 */
	Queue();

	/**
	 * @brief      Insert element in Queue
	 *
	 * @param[in]  item  The item
	 */
	void enqueue(const T& item);

	/**
	 * @brief      Pull element out of Queue
	 *
	 * @return     A copy of the pulled element
	 */
	T dequeue();

	/**
	 * @brief      return number of elements in the queue
	 *
	 * @return     Number of elements in queue
	 */
	uint32_t size();

	/**
	 * @brief      Determines if empty.
	 *
	 * @return     True if empty, False otherwise.
	 */
	bool isEmpty();

private:

	uint32_t capacity_ = 1;

	uint32_t numOfElements_ = 0;

	std::shared_ptr<T> queuePointer_;

	uint32_t firstElement_ = 0;
	uint32_t lastElement_ = 0;

	void resize(const uint32_t& newSize);
};

#include <QueueImpl.hpp>

#endif