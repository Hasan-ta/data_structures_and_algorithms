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

template <class T> Dequeue<T>::Dequeue(const bool& optimizeMemory) : optimizeMemory_(optimizeMemory){}

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
	T ret = *(dequeuePtr_.get() + frontPointer_++); 
	if(numOfElements_ <= capacity_/2 && optimizeMemory_)
		resize(capacity_/2);
	return ret;
}

template <class T> T Dequeue<T>::removeRear()
{
	--numOfElements_;
	T ret = *(dequeuePtr_.get() + --rearPointer_);
	if(numOfElements_ <= capacity_/2 && optimizeMemory_)
		resize(capacity_/2);
	return ret;
}

template <class T> uint32_t Dequeue<T>::size()
{
	return numOfElements_;
}

template <class T> bool Dequeue<T>::isEmpty()
{
	return numOfElements_ == 0;
}

template <class T> void Dequeue<T>::resize(const uint32_t& newSize)
{
	capacity_ = newSize;
	std::unique_ptr<T> reallocationPtr = std::unique_ptr<T>(new T[capacity_]);
	uint32_t tempHalfWayPointer = capacity_/2;
	// uint32_t startCopyLocation = (tempHalfWayPointer - numOfElements_/2)*sizeof(T);
	uint32_t startCopyLocation = (tempHalfWayPointer - numOfElements_/2);
	// uint32_t copySize = (rearPointer_- frontPointer_)*sizeof(T);
	uint32_t copySize = (rearPointer_- frontPointer_);
	// std::memcpy(reallocationPtr.get()+startCopyLocation, dequeuePtr_.get()+frontPointer_*sizeof(T), copySize);
	int counter = startCopyLocation;
	for(int i = frontPointer_; i < rearPointer_; ++i)
	{
		*(reallocationPtr.get()+counter) = *(dequeuePtr_.get()+i);
		counter++;
	}
	frontPointer_ = tempHalfWayPointer - numOfElements_/2;
	rearPointer_ = frontPointer_+copySize;
	dequeuePtr_ = std::move(reallocationPtr);
}

#endif
