#ifndef STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUEIMPL_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUEIMPL_HPP

#include <math.h>
#include <cstring>

template <class T> Dequeue<T>::Dequeue()
{
	dequeuePtr_ = std::shared_ptr<T>(new T[capacity_], std::default_delete<T>());
	halfWayPointer_ = capacity_ / 2;
	frontPointer_ = rearPointer_ = halfWayPointer_;
}

template <class T> void Dequeue<T>::addFront(const T& element)
{
	if(rearPointer_ == capacity_ || frontPointer_ == 0)
		resize(capacity_*2);

	*(dequeuePtr_.get() + --frontPointer_) = element;
	numOfElements_++;
}

template <class T> void Dequeue<T>::addRear(const T& element)
{
	if(rearPointer_ == capacity_ || frontPointer_ == 0)
		resize(capacity_*2);

	*(dequeuePtr_.get() + rearPointer_++) = element;
	numOfElements_++;
}

template <class T> T Dequeue<T>::removeFront()
{
	--numOfElements_;
	return *(dequeuePtr_.get() + frontPointer_++);
}

template <class T> T Dequeue<T>::removeRear()
{
	--numOfElements_;
	return *(dequeuePtr_.get() + rearPointer_--);
}

template <class T> void Dequeue<T>::resize(const uint32_t& newSize)
{
	capacity_ = newSize;
	std::unique_ptr<T> reallocationPtr = std::unique_ptr<T>(new T[capacity_]);
	uint32_t tempHalfWayPointer = capacity_/2;
	uint32_t startCopyLocation = (tempHalfWayPointer - numOfElements_/2)*sizeof(T);
	uint32_t copySize = (rearPointer_- frontPointer_)*sizeof(T);
	std::memcpy(reallocationPtr.get()+startCopyLocation, dequeuePtr_.get()+frontPointer_*sizeof(T), copySize);
	frontPointer_ = tempHalfWayPointer - numOfElements_/2;
	rearPointer_ = frontPointer_+copySize;
	dequeuePtr_ = std::move(reallocationPtr);
}

#endif
