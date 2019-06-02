#include "Direct_Graph_AList.h"
#include "Priority_Queue.h"
#include "Disjoint_Set.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

	Direct_Graph_AList::Direct_Graph_AList(int _n): n{_n}
	{
		a_list = new Adjacency_List[n];
	}

	Direct_Graph_AList::Direct_Graph_AList( Direct_Graph_AMatrix& copy_g )
	{
		n = copy_g.get_n();
		a_list = new Adjacency_List[n];

		for(int i=0; i<n; i++)
		{
			for(int k=0; k<n; k++)
				if(copy_g.matrix[i][k] != Edge::NOT_AN_EDGE)
					add_edge(i, k, copy_g.matrix[i][k]);
		}
	}

	Direct_Graph_AList::~Direct_Graph_AList()
	{
		delete[] a_list;
	}

	//return NOT_AN_EDGE if edge is not found
	int Direct_Graph_AList::edge_weight(int source, int dest)
	{
		return a_list[source].get_weight(dest);
	}

//Dijkstra(G,w,s):
//   dla każdego wierzchołka v w V[G] wykonaj
//      d[v] := nieskończoność
//      poprzednik[v] := niezdefiniowane
//   d[s] := 0
//   Q := V
//   dopóki Q niepuste wykonaj
//      u := Zdejmij_Min(Q)
//      dla każdego wierzchołka v – sąsiada u wykonaj
//         jeżeli d[v] > d[u] + w(u, v) to
//            d[v] := d[u] + w(u, v)
//            poprzednik[v] := u
//
//   Wyświetl("Droga wynosi: " + d[v])

	void Direct_Graph_AList::Dijkstra(int start, int* dist, int* prev)
	{
		Priority_Queue q{n};
		Edge temp_edge;
		Node* edge_node;
		for(int i=0; i<n; i++)
		{
			dist[i] = Edge::NOT_AN_EDGE;
			prev[i] = i;
			q.push( {i,i,dist[i]} );
		}
		q.decrease_key( {start, start, Edge::NOT_AN_EDGE}, start, 0);
		dist[start] = 0;

		int i, k;
		while(q.get_size()>0)
		{
			temp_edge = q.pop();
			i = temp_edge.dest;
			dist[i] = temp_edge.weight;
			//prev[i] =
			edge_node = a_list[i].head;

			while(edge_node != nullptr)
				{
					k = edge_node->dest;
					if (	edge_node->weight != Edge::NOT_AN_EDGE
							&& dist[k]  > dist[i]+edge_node->weight
						)
					{
						q.decrease_key({i, k, dist[k]}, i, dist[i]+edge_node->weight );
						prev[k] = i;
						dist[k] = dist[i]+edge_node->weight ;
					}
					edge_node = edge_node->next;
				}
		}
		return;
	}





	int Direct_Graph_AList::get_edge_degree(int source)
	{
		return a_list[source].get_size();
	}


	void Direct_Graph_AList::gen(int _n, double proc, int min_w, int max_w)
	{
		this->clear();
		n = _n;
		a_list = new Adjacency_List[n];


		int max_number_of_edges = (n*(n-1));
		int number_of_edges = ceil(max_number_of_edges*proc*0.01);

		int dest, source;
		int i_weight;
		int i;
		Disjoint_Set d_set{n};
		//pętla generująca "drzewo" rozpinające z podwojonymi krawędziami
		//krewedzie dodane są w obu kierunkach aby zapewnić osiągalność wszystkich wierzchołków
		//
		//rozpoczyna od lasu z n drzewami w postaci poj. wierzchołków
		//łączy wierzchołki z róznych drzew w lesie, scala te dwa drzewa w jedno
		i=0;
		while(i<n+n-2)
		{
			source = rand()%n;
			dest = rand()%n;
			if	(
					source != dest
					&& d_set.find(source) != d_set.find(dest)
					&& this->edge_weight(source, dest) == Edge::NOT_AN_EDGE
				)
			{
				i_weight = rand()% (max_w-min_w+1) + min_w ;
				add_edge(source , dest, i_weight);
				i_weight = rand()% (max_w-min_w+1) + min_w ;
				add_edge(dest, source, i_weight);
				d_set.join(source, dest);
				i++;
				i++;
			}
		}

		//generuje resztę krawedzi
		while(i<number_of_edges)
		{
			source = rand()%n;
			dest = rand()%n;
			if(source!=dest && this->edge_weight(source, dest)==Edge::NOT_AN_EDGE)
			{
				i_weight = rand()% (max_w-min_w+1) + min_w ;
				add_edge(source, dest, i_weight);
				i++;
			}
		}

	}

	void Direct_Graph_AList::add_edge(int s, int dest, int w)
	{
		a_list[s].insert_beg(dest, w);
	}

	void Direct_Graph_AList::clear()
	{
		delete[] a_list;
		n = 0;
	}

	void Direct_Graph_AList::load_from_file(std::string f_name)
	{
		//
		//	TODO	//////////////////
		//
		clear();
		std::fstream file;
		std::string input;
		int _n, _k;
		int source, dest, weight;
		file.open( f_name , std::ios::in );
		if( file.good() == true )
		{
		    file >> _k >> _n;
		    n = _n;
		    a_list = new Adjacency_List[n];

			while(!file.eof() && _k--)
			{
				file>>source>>dest>>weight;

				this->add_edge(source, dest, weight);
			}

			//tu operacje na pliku (zapis/odczyt)
			file.close();
		}
	}

	void Direct_Graph_AList::display()
	{
		std::cout<<"Graf - reprezentacja: lista sasiedztwa "<<std::endl;
		for(int i=0; i<n; i++)
		{
			std::cout<<"source: "<<i<< "-->-";
			a_list[i].print();
		}
	}

