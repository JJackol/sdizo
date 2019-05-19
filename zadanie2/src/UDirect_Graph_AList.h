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
		void add_vertex(int source, int dest, int w);
		void gen(int _n, int proc, int min_w=0, int max_w=100);
		int get_vert_degree(int source);

		void display();
};

#endif // GRAPH_ALIST_H
