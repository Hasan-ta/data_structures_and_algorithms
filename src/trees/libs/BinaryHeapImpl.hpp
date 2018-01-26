#ifndef TREES_LIBS_BINARYHEAPIMPL_HPP
#define TREES_LIBS_BINARYHEAPIMPL_HPP

template <class T> BinaryHeap<T>::BinaryHeap()
{}

template <class T> void BinaryHeap<T>::insert(const T& newItem)
{
	heapList_.append(newItem);
	int i = heapList_.size()-1;
	percUp(i);
}

template <class T> void BinaryHeap<T>::percUp(int i)
{
	while((i-1)/2 >= 0 && i > 0)
	{
		if(heapList_[i] < heapList_[(i-1)/2])
		{
			T temp = heapList_[(i-1)/2];
			heapList_[(i-1)/2] = heapList_[i];
			heapList_[i] = temp;
		}
		i = (i-1)/2;
	}
}

template <class T> T BinaryHeap<T>::delMin()
{
	T retVal = heapList_[0];
	heapList_[0] = heapList_[heapList_.size()-1];
	heapList_.pop();
	percDown(0);
	return retVal;	
}

template <class T> void BinaryHeap<T>::percDown(int i)
{
	while(i*2+1 < heapList_.size())
	{
		T mc = minChild(i);
		if(heapList_[i] > heapList_[mc])
		{
			T temp1 = heapList_[mc];
			heapList_[mc] = heapList_[i];
			heapList_[i] = temp1;
		}
		i = mc;
	}
}

template <class T> int BinaryHeap<T>::minChild(const int i)
{
	if(i*2+2 >= heapList_.size())
	{
		return i*2+1;
	}
	else
	{
		if(heapList_[i*2+1] < heapList_[i*2+2])
			return i*2+1;
		else
			return i*2+2;
	}
}
#endif
