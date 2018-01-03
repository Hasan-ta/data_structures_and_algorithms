#ifndef STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUEIMPL_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_DEQUEUEIMPL_HPP

Dequeue<T>::Dequeue()
{
	dequeuePtr_ = std::shared_ptr<T>(new T[capacity_], std::default_delete<T>());
	halfWayPointer_ = cpacity_ / 2;
	frontPointer_ = rearPointer_ = halfWayPointer_;
}

void Dequeue<T>::addFront(const T& element)
{
	if(numofElements == capacity_/2);
		resize(capacity_*2);

	*--frontPointer_ = element;
	numofElements++;
}

void Dequeue<T>::addRear(const T& element)
{
	if(numofElements == capacity_/2);
		resize(capacity_*2);

	*rearPointer_++ = element;
	numofElements++;
}

T Dequeue<T>::removeFront()
{
	--numofElements;
	return *frontPointer_++;
}

T Dequeue<T>::removeRear()
{
	--numofElements;
	return *rearPointer_--;
}

void Dequeue<T>::resize(const uint32_t& newSize)
{
	capacity_ = newSize;
	std::unique_ptr<T> reallocationPtr = std::unique_ptr<T>(new T[capacity_]);
	uint32_t tempHalfWayPointer = capacity_/2;
	uint32_t startCopyLocation = tempHalfWayPointer - frontPointer_*sizeof(T);
	uint32_t copySize = (rearPointer_- frontPointer_)*sizeof(T);
	std::memcpy(reallocationPtr.get()+startCopyLocation, dequeuePtr_.get()+frontPointer_*sizeof(T), copySize);
	dequeuePtr_ = std::move(reallocationPtr);
}


#endif
