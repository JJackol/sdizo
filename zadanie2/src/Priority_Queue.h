#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template <class T>
class Priority_Queue
{
	T* heap;
	int aloc_size;
	int _size;
	public:
		Priority_Queue(int aloc_size=16);
		virtual ~Priority_Queue();
		void push(T el);
		T pop();

	protected:

	private:
};

#endif // PRIORITY_QUEUE_H
