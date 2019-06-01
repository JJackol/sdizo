#include "UDirect_Graph_AList.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

	UDirect_Graph_AList::UDirect_Graph_AList(int _n): n{_n}
	{
		a_list = new Adjacency_List[n];
	}

	UDirect_Graph_AList::UDirect_Graph_AList( UDirect_Graph_AMatrix& copy_g )
	{
		n = copy_g.get_n();
		a_list = new Adjacency_List[n];

		for(int i=0; i<n; i++)
		{
			for(int k=i; k<n; k++)
				if(copy_g.matrix[i][k] != NOT_AN_EDGE_UD)
					add_edge(i, k, copy_g.matrix[i][k]);
		}
	}

	UDirect_Graph_AList::~UDirect_Graph_AList()
	{
		delete[] a_list;
	}

	int UDirect_Graph_AList::edge_weight(int source, int dest)
	{
		return a_list[source].get_weight(dest);
	}

	Edge_List UDirect_Graph_AList::Prim()
	{

		Edge_List MST;
		int start_nod = rand()%n;

		int i = 0;
		while(i<n-1)
		{

		}
	}


	int UDirect_Graph_AList::get_edge_degree(int source)
	{
		return a_list[source].get_size();
	}

	/**
	* dont use this f.
	*
	*/
	void UDirect_Graph_AList::gen(int _n, double proc, int min_w, int max_w)
	{
		delete[] a_list;
		n = _n;
		a_list = new Adjacency_List[n];
		int max_number_of_edges = n*(n-1)/2;
		int number_of_edges = ceil(max_number_of_edges*proc);

		int join;
		int i_weight;
		int i;
		//pętla generująca drzewo rozpinające
		//dołącza kolejne wierzchołki do już istniejącego drzewa
		for (i = 1; i<n; i++)
		{
			join = rand()%i;
			i_weight = rand()% (max_w-min_w+1) - min_w ;
			add_edge(join, i, i_weight);
			add_edge(i, join, i_weight);
		}
	}

	void UDirect_Graph_AList::add_edge(int s, int dest, int w)
	{
		a_list[s].insert_beg(dest, w);
		a_list[dest].insert_beg(s, w);
	}

	void UDirect_Graph_AList::display()
	{
		for(int i=0; i<n; i++)
		{
			std::cout<<"source: "<<i<< "-->-";
			a_list[i].print();
		}
	}
