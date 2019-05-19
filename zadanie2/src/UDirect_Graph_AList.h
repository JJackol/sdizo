#ifndef GRAPH_ALIST_H
#define GRAPH_ALIST_H

#include "Adjacency_List.h"


class UDirect_Graph_AList
{
	int n; // n= |V|
	Adjacency_List* a_list;

	public:
		UDirect_Graph_AList(int _n);
		virtual ~UDirect_Graph_AList();

		void display();
};

#endif // GRAPH_ALIST_H
