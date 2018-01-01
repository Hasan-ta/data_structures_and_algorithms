#ifndef STACKS_QUEUES_DEQUEUES_LIBS_STACKIMPL_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_STACKIMPL_HPP

#include <cstring>
#include <exception>

template <class T> Stack<T>::Stack()
{
	stackBase_ = std::shared_ptr<T>(new T[capacity_], std::default_delete<T[]>());
	stackHead_ = stackBase_.get();
}

template <class T> bool Stack<T>::push(const T& item)
{
	if(numOfItems_ == capacity_)
		resize(2*capacity_);

	*stackHead_++ = item;
	++numOfItems_;

	return true;
}

template <class T> T Stack<T>::pop()
{
	if(stackHead_ == stackBase_.get())
		throw std::runtime_error("Trying to pop an empty stack");
	else
	{
		--numOfItems_;
		T ret = *--stackHead_;

		if(numOfItems_ <= capacity_/2)
			resize(capacity_/2);
		return ret;
	}
}

template <class T> T Stack<T>::peek()
{
	if(stackHead_ == stackBase_.get())
		throw std::runtime_error("Trying to peek an empty stack");
	else
	{
		return *stackHead_;
	}
}

template <class T> uint32_t Stack<T>::size()
{
	return numOfItems_;
}

template <class T> bool Stack<T>::isEmpty()
{
	return numOfItems_ == 0;
}

template <class T> void Stack<T>::resize(const int& newSize)
{
	capacity_ = newSize;
	std::unique_ptr<T> reallocationPtr = std::unique_ptr<T>(new T[capacity_]);
	std::memcpy(reallocationPtr.get(), stackBase_.get(), numOfItems_*sizeof(T));
	stackBase_ = std::move(reallocationPtr);
	stackHead_ = stackBase_.get()+numOfItems_;
}
	
#endif