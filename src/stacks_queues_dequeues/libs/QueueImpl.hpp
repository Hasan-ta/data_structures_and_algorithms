#ifndef STACKS_QUEUES_DEQUEUES_LIBS_QUEUEIMPL_HPP
#define STACKS_QUEUES_DEQUEUES_LIBS_QUEUEIMPL_HPP

#include <exception>

template <class T> Queue<T>::Queue()
{
	queuePointer_ = std::shared_ptr<T>(new T[capacity_], std::default_delte<T>());
	firstElement_ = queuePointer_.get();
	lastElement_ = firstElement_;
}

template <class T> void Queue<T>::enqueu(const T& element)
{
	
}

#endif