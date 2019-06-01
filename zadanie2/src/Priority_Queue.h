#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Edge.h"

class Priority_Queue
{
	Edge* tab;
	int aloc_size;
	int _size;
	public:
		Priority_Queue(int aloc_size=16);
		virtual ~Priority_Queue();
		void push(Edge el);
		Edge pop();
		void decrease_key(Edge e, int new_source, int new_key);



		void display();
	protected:
		void heapify_up(int index);
		void heapify_down(int index);
	private:
};

#endif // PRIORITY_QUEUE_H
