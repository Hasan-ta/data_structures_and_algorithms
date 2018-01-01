#ifndef STACKS_QUEUES_DEQUEUES_LIBS_QUEUE_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_QUEUE_HPP

#include <memory>

template <class T> class Queue{
public:

	Queue();

	void enqueue(const T& item);

	T dequeue();

	uint32_t size();

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