#ifndef TREES_LIBS_BINARYHEAP_HPP
#define TREES_LIBS_BINARYHEAP_HPP

#include "DynamicArray.hpp"
#include <stdint.h>

template <class T> class BinaryHeap{
public:
	
	BinaryHeap();

	BinaryHeap(DynamicArray<T> alist);

	void insert(const T& newItem);

	T delMin();

private:

	DynamicArray<T> heapList_;

	void percUp(int i);

	void percDown(int i);

	int minChild(const int i);
};

#include "BinaryHeapImpl.hpp"

#endif 
