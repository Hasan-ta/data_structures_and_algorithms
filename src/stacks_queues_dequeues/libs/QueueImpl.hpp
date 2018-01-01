#ifndef STACKS_QUEUES_DEQUEUES_LIBS_QUEUEIMPL_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_QUEUEIMPL_HPP

#include <exception>
#include <cstring>

template <class T> Queue<T>::Queue()
{
	queuePointer_ = std::shared_ptr<T>(new T[capacity_], std::default_delete<T>());
}

template <class T> void Queue<T>::enqueue(const T& item)
{
	if(numOfElements_ == capacity_)
		resize(capacity_*2);

	*(queuePointer_.get()+lastElement_) = item;
	lastElement_++; numOfElements_++;
}

template <class T> T Queue<T>::dequeue()
{
	if(lastElement_ == firstElement_)
		throw std::runtime_error("Trying to dequeue an empty queue");
	else
	{
		T ret = *(queuePointer_.get()+firstElement_);
		numOfElements_--; firstElement_++;
		if(numOfElements_ <= capacity_/2)
			resize(capacity_/2);
		return ret;
	}
}

template <class T> void Queue<T>::resize(const uint32_t& newSize)
{
	capacity_ = newSize;
	std::unique_ptr<T> reallocationPtr = std::unique_ptr<T>(new T[capacity_]);
	int counter = 0;
	for (int i = firstElement_; i <lastElement_; ++i)
	{
		*(reallocationPtr.get()+counter) = *(queuePointer_.get()+i);
		counter++;
	}
	// For some reason memcpy didn't work as expected
	// std::memcpy(reallocationPtr.get(), queuePointer_.get()+firstElement_*sizeof(T), (lastElement_-firstElement_)*sizeof(T));
	firstElement_ = 0; lastElement_ = numOfElements_;
	queuePointer_ = std::move(reallocationPtr);
}

#endif