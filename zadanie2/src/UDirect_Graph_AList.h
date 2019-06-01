#ifndef GRAPH_ALIST_H
#define GRAPH_ALIST_H

#include "Adjacency_List.h"
#include "UDirect_Graph_AMatrix.h"
#include "Edge_List.h"


class UDirect_Graph_AList
{
	int n; // n= |V|
	Adjacency_List* a_list;

	public:
		UDirect_Graph_AList(int _n);
		UDirect_Graph_AList(UDirect_Graph_AMatrix& copy_g);
		virtual ~UDirect_Graph_AList();
		int get_n(){return n;};

		int edge_weight(int source, int dest);

		Edge_List Prim();


		void add_edge(int source, int dest, int w);
		void gen(int _n, double proc, int min_w=0, int max_w=100);
		int get_edge_degree(int source);

		void display();
};

#endif // GRAPH_ALIST_H
