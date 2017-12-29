#ifndef DYNAMIC_ARRAYS_LIBS_DYNAMICARRAYIMPL_HPP
#define DYNAMIC_ARRAYS_LIBS_DYNAMICARRAYIMPL_HPP

#include <exception>
#include <sstream>
#include <string>

template <typename T>  DynamicArray<T>::DynamicArray()
{
	arrayPointer_ = std::shared_ptr<T>(new T[capacity_], std::default_delete<T[]>());
}

template <typename T> DynamicArray<T>::DynamicArray(const uint32_t& capacity)
{
	capacity_ = capacity;
	arrayPointer_ = std::shared_ptr<T>(new T[capacity_], std::default_delete<T[]>());
}

template <typename T> DynamicArray<T>::DynamicArray(const uint32_t& capacity, const T& value)
{
	capacity_ = capacity;
	numOfElements_ = capacity_;
	arrayPointer_ = std::shared_ptr<T>(new T[capacity_], std::default_delete<T[]>());

	for (uint32_t i = 0; i < capacity_; ++i)
	{
		*(arrayPointer_.get()+i) = value;
	}
}

template <typename T> uint32_t DynamicArray<T>::size() const
{
	return numOfElements_;
}

template <typename T> T DynamicArray<T>::operator[](const uint32_t& i) const
{
	if(i <= numOfElements_)
		return *(arrayPointer_.get()+i);
	else
	{
		std::stringstream ss; ss <<"Index: " << i << " larger than array size\n";
		throw std::range_error(ss.str());
	}

}

template <typename T> void DynamicArray<T>::append(const T& element)
{
	if(numOfElements_ == capacity_)
	{
		resize();
	}
	*(arrayPointer_.get()+numOfElements_) = element;
	++numOfElements_;
}

template <typename T> void DynamicArray<T>::resize()
{
	capacity_ *= 2;
	std::unique_ptr<T[]> reallocationPtr(new T[capacity_]);
	for (uint32_t i = 0; i < numOfElements_; ++i)
	{
		*(reallocationPtr.get()+i) = *(arrayPointer_.get()+i);
	}
	arrayPointer_ = std::move(reallocationPtr);
}

#endif