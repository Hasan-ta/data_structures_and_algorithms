#ifndef DYNAMIC_ARRAYS_LIBS_DYNAMICARRAYIMPL_HPP
#define DYNAMIC_ARRAYS_LIBS_DYNAMICARRAYIMPL_HPP

#include <exception>
#include <sstream>
#include <string>
#include <cstring>

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

template <typename T> uint32_t DynamicArray<T>::capacity() const
{
	return capacity_;
}

template <typename T> const T& DynamicArray<T>::operator[](const uint32_t& i) const
{
	if(i <= numOfElements_)
		return *(arrayPointer_.get()+i);
	else
	{
		std::stringstream ss; ss <<"Index: " << i << " larger than array size\n";
		throw std::range_error(ss.str());
	}

}

template <typename T> T& DynamicArray<T>::operator[](const uint32_t& i)
{
	return const_cast<T&>(static_cast<const DynamicArray*>(this)->operator[](i));
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

template <typename T> T DynamicArray<T>::pop()
{
	return *(arrayPointer_.get()+(numOfElements_--)-1);
	// --numOfElements_
	// return retValue
}

template <typename T> void DynamicArray<T>::resize()
{
	capacity_ *= 2;
	std::unique_ptr<T[]> reallocationPtr(new T[capacity_]);
	std::memcpy(reallocationPtr.get(), arrayPointer_.get(), numOfElements_*sizeof(T));
	arrayPointer_ = std::move(reallocationPtr);
}

template <typename T> typename DynamicArray<T>::const_iterator DynamicArray<T>::begin() const
{
	return arrayPointer_.get();
}

template <typename T> typename DynamicArray<T>::iterator DynamicArray<T>::begin()
{
	return arrayPointer_.get();
}

template <typename T> typename DynamicArray<T>::const_iterator DynamicArray<T>::end() const
{
	return arrayPointer_.get()+numOfElements_;
}

template <typename T> typename DynamicArray<T>::iterator DynamicArray<T>::end()
{
	return arrayPointer_.get()+numOfElements_;
}

#endif