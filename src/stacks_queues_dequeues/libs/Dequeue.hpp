#ifndef STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUE_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUE_HPP

#include <memory>

template <class T> class Dequeue{
public:

	Dequeue();

	void addFront(const T& element);

	void addRear(const T& element);

	T removeFront();

	T removeRear();

	uint32_t size();

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