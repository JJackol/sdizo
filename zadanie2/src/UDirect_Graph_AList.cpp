#include "UDirect_Graph_AList.h"
#include <iostream>
#include <cstdlib>

	UDirect_Graph_AList::UDirect_Graph_AList(int _n): n{_n}
	{
		a_list = new Adjacency_List[n];
	}

	UDirect_Graph_AList::~UDirect_Graph_AList()
	{
		delete[] a_list;
	}

	void UDirect_Graph_AList::display()
	{
		for(int i=0; i<n; i++)
		{
			std::cout<<"source: "<<i<< "-->-";
			a_list[i].print();
		}
	}

	int UDirect_Graph_AList::get_vert_degree(int source)
	{
		return a_list[source].get_size();
	}

	void UDirect_Graph_AList::add_vertex(int s, int dest, int w)
	{
		a_list[s].insert_beg(dest, w);
	}

	void UDirect_Graph_AList::gen(int _n, int proc, int min_w, int max_w)
	{
		delete[] a_list;
		n = _n;
		a_list = new Adjacency_List[n];
		int number_of_edges = n*(n-1)/2;
		number_of_edges = number_of_edges*proc / 100;

		int join;
		int i_weight;

		for (int i = 1; i<n; i++)
		{
			join = rand()%i;
			i_weight = rand()% (max_w-min_w+1) - min_w ;
			add_vertex(join, i, i_weight);
			add_vertex(i, join, i_weight);

		}


	}
