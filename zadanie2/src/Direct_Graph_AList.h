#ifndef DIRECT_GRAPH_ALIST_H
#define DIRECT_GRAPH_ALIST_H

#include "Adjacency_List.h"
#include "Direct_Graph_AMatrix.h"
#include "Edge_List.h"
#include <string>


class Direct_Graph_AList
{
	int n; // n= |V|
	Adjacency_List* a_list;

	public:
		Direct_Graph_AList(int _n);
		Direct_Graph_AList(Direct_Graph_AMatrix& copy_g);
		virtual ~Direct_Graph_AList();
		int get_n(){return n;};

		int edge_weight(int source, int dest);

		void Dijkstra(int start, int* dist, int* prev);



		void add_edge(int source, int dest, int w);
		void gen(int _n, double proc, int min_w=0, int max_w=100);
		int get_edge_degree(int source);
		void clear();

		void load_from_file(std::string f_name);
		void display();
};



#endif // DIRECT_GRAPH_ALIST_H
