#ifndef STACKS_QUEUES_DEQUEUES_LIBS_STACK_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_STACK_HPP

#include <memory>

template <class T> class Stack{
public:
	Stack();

	bool push(const T& item);

	T& pop();

	T peek();

	uint32_t size();

	bool isEmpty();

private:

	T* stackHead_;
	
	std::shared_ptr<T> stackBase_;

	uint32_t capacity_ = 1;

	uint32_t numOfItems_ = 0;

	void resize();

};

#include "StackImpl.hpp"

#endif 