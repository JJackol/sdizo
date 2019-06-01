#include "Priority_Queue.h"

template <class T>
Priority_Queue<T>::Priority_Queue(int aloc_size): aloc_size{aloc_size}
{
	heap = new T[aloc_size];

}

template <class T>
Priority_Queue<T>::~Priority_Queue()
{
	delete[] heap;
}

template <class T>
void Priority_Queue<T>::push(T el)
{

}

template <class T>
T Priority_Queue<T>::pop()
{
		if(_size == 0)
			return
		_size--;

		//tab[0] = tab[size];
		//heapify_down(0);
}
