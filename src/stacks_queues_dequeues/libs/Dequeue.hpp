#ifndef STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUE_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUE_HPP

#include <memory>

template <class T> Dequue{
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

	capacity_ = 2;

};

#endif 