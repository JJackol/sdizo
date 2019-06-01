#include "UDirect_Graph_AList.h"
#include "Priority_Queue.h"
#include "Disjoint_Set.h"
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

	//return NOT_AN_EDGE if edge is not found
	int UDirect_Graph_AList::edge_weight(int source, int dest)
	{
		return a_list[source].get_weight(dest);
	}

	Edge_List UDirect_Graph_AList::Kruskal()
	{
		Edge_List mst;
		Disjoint_Set forest{n};
		Priority_Queue q{ (n*(n-1)) };
		int temp_w;
		Edge temp_edge;
		Node* edge_node;

		for(int i=0; i<n; i++)
		{
			edge_node = a_list[i].head;
			while(edge_node != nullptr)
			{
				q.push( {i, edge_node->dest, edge_node->weight} );
				edge_node = edge_node->next;
			}

			//////////
//			for(int j=0; j<i; j++)
//			{
//				temp_w = this->edge_weight(i, j);
//				if (temp_w!=NOT_AN_EDGE)
//					q.push( {i, j, temp_w} );
//			}
		}

		int mst_edges=0;
		while (mst_edges<n-1)
		{
			temp_edge = q.pop();
			if ( forest.find(temp_edge.source) != forest.find(temp_edge.dest) )
			{
				mst.insert_beg(temp_edge);
				forest.join(temp_edge.source, temp_edge.dest);
				mst_edges++;
			}

		}

		return mst;
	}

	Edge_List UDirect_Graph_AList::Prim()
	{
		/////////////////
		Edge_List mst;
		bool is_in_tree[n];
		int cost[n];
		Priority_Queue q{n};
		Edge popped;
		Node* edge_node;
		int k;
		//init loop
		for (int i=0; i<n; i++)
		{
			q.push( {-1, i, Edge::NOT_AN_EDGE} );
			is_in_tree[i] = false;
			cost[i] = Edge::NOT_AN_EDGE;
		}

		int i=1, start = rand()%n;
		cost[start] = 0;
		is_in_tree[start] = true;


		while(i<n)
		{

				edge_node = a_list[start].head;
				while(edge_node != nullptr)
				{
					k = edge_node->dest;
					if (	edge_node->weight != Edge::NOT_AN_EDGE
							&& edge_node->weight  < cost[k]
							&& !is_in_tree[k])
					{
						q.decrease_key({start, k, cost[k]}, start, edge_node->weight );
						cost[k] = edge_node->weight ;
					}
					edge_node = edge_node->next;
				}

				popped = q.pop();

				cost[popped.dest] = cost[popped.source]+edge_weight(popped.dest, popped.source);
				is_in_tree[popped.dest] = true;
				mst.insert_beg( {popped.source, popped.dest, edge_weight(popped.dest, popped.source) } );
				start = popped.dest;
				i++;

		}
		return mst;
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
		this->clear();
		n = _n;
		a_list = new Adjacency_List[n];

		{
			int max_number_of_edges = (n*(n-1))/2;
			int number_of_edges = ceil(max_number_of_edges*proc*0.01);

			int dest, source;
			int i_weight;
			int i;
			Disjoint_Set d_set{n};
			//pętla generująca drzewo rozpinające
			//rozpoczyna od lasu z n drzewami w postaci poj. wierzchołków
			//łączy wierzchołki z róznych drzew w lesie, scala te dwa drzewa w jedno
			i=1;
			while(i<n)
			{
				source = rand()%n;
				dest = rand()%n;
				if	(
						source != dest
						&& d_set.find(source) != d_set.find(dest)
						&& this->edge_weight(source, dest) == NOT_AN_EDGE_UD
					)
				{
					i_weight = rand()% (max_w-min_w+1) + min_w ;
					add_edge(source , dest, i_weight);
					d_set.join(source, dest);
					i++;
				}
			}

			//generuje resztę wierzchołków
			while(i<=number_of_edges)
			{
				source = rand()%n;
				dest = rand()%n;
				if(source!=dest && this->edge_weight(source, dest)==NOT_AN_EDGE_UD)
				{
					i_weight = rand()% (max_w-min_w+1) + min_w ;
					add_edge(source, dest, i_weight);
					i++;
				}
			}
		}
	}

	void UDirect_Graph_AList::add_edge(int s, int dest, int w)
	{
		a_list[s].insert_beg(dest, w);
		a_list[dest].insert_beg(s, w);
	}

	void UDirect_Graph_AList::clear()
	{
		delete[] a_list;
		n = 0;
	}

	void UDirect_Graph_AList::display()
	{
		std::cout<<"Graf - reprezentacja: lista sasiedztwa "<<std::endl;
		for(int i=0; i<n; i++)
		{
			std::cout<<"source: "<<i<< "-->-";
			a_list[i].print();
		}
	}
