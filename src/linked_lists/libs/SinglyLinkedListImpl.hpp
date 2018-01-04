#ifndef LINKED_LISTS_LIBS_SINGLYLINKEDLISTImpl_HPP
#define LINKED_LISTS_LIBS_SINGLYLINKEDLISTImpl_HPP

template <class T> typename SinglyLinkedList<T>::Node::Node(const T& element, T* nextPointer)
{
	element_ = element;
	nextPointer_ = std::unique_ptr<T>(nextPointer);
}

template <class T> typename SinglyLinkedList<T>::Node::Node(const T& element, std::unique_ptr<T> nextPointer)
{
	element_ = element;
	nextPointer_ = nextPointer;
}

template <class T> SinglyLinkedList<T>::SinglyLinkedList()
{
	head_ = std::shared_ptr<T>(new T);	
}

template <class T> void SinglyLinkedList<T>::append(const T& value)
{
}

#endif