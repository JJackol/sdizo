#include "UDirect_Graph_AMatrix.h"
#include "Disjoint_Set.h"
#include "Priority_Queue.h"
#include <iostream>
#include <iomanip>
#include <cmath>


	UDirect_Graph_AMatrix::UDirect_Graph_AMatrix(int _n): n{_n}
	{
		matrix = new int*[n];
		for(int i=0; i<n; i++)
		{
			matrix[i] = new int[n];
			for(int k=0; k<n; k++)
				matrix[i][k] = NOT_AN_EDGE_UD;
		}
	}

	UDirect_Graph_AMatrix::~UDirect_Graph_AMatrix()
	{
		this->clear();
	}

	int UDirect_Graph_AMatrix::edge_weight(int source, int dest)
	{
		return matrix[source][dest];
	}

	bool UDirect_Graph_AMatrix::add_edge(int source, int dest, int w)
	{
		matrix[source][dest] = w;
		matrix[dest][source] = w;
		return true;
	}



	void UDirect_Graph_AMatrix::gen(int _n, double proc, int min_w, int max_w)
	{
		this->clear();
		n = _n;
		matrix = new int*[n];
		for(int i=0; i<n; i++)
		{
			matrix[i] = new int[n];
		}

		{
			for(int i=0; i<n; i++)
			{
				for(int k=0; k<n; k++)
					matrix[i][k] = NOT_AN_EDGE_UD;
			}

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
						&& matrix[source][dest] == NOT_AN_EDGE_UD
					)
				{
					i_weight = rand()% (max_w-min_w+1) + min_w ;
					add_edge(source , dest, i_weight);
					d_set.join(source, dest);
					i++;
				}
			}

			//generuje resztę krawędzi
			while(i<=number_of_edges)
			{
				source = rand()%n;
				dest = rand()%n;
				if(source!=dest && matrix[source][dest]==NOT_AN_EDGE_UD)
				{
					i_weight = rand()% (max_w-min_w+1) + min_w ;
					add_edge(source, dest, i_weight);
					i++;
				}
			}
		}
	}

	void UDirect_Graph_AMatrix::make_complete(int min_w, int max_w)
	{
		for(int i=0; i<n; i++)
		{
			for(int k=0; k<n; k++)
				if(i!=k)
					matrix[i][k] = rand()% (max_w-min_w+1) - min_w ;
		}
	}

	Edge_List UDirect_Graph_AMatrix::Prim()
	{
		Edge_List mst;
		bool is_in_tree[n];
		int cost[n];
		Priority_Queue q{n};
		Edge popped;

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

			for(int k=0; k<n; k++)
			{
				if (	matrix[start][k] != Edge::NOT_AN_EDGE
						&& matrix[start][k] < cost[k]
						&& !is_in_tree[k])
				{
					q.decrease_key({start, k, cost[k]}, start, matrix[start][k]);
					cost[k] = matrix[start][k];
				}
			}

			popped = q.pop();

			cost[popped.dest] = cost[popped.source]+matrix[popped.dest][popped.source];
			is_in_tree[popped.dest] = true;
			mst.insert_beg( {popped.source, popped.dest, matrix[popped.dest][popped.source]} );
			start = popped.dest;
			i++;
		}
		return mst;
	}

	Edge_List UDirect_Graph_AMatrix::Kruskal()
	{
		Edge_List mst;
		Disjoint_Set forest{n};
		Priority_Queue q{ (n*(n-1))/2 };
		int temp_w;
		Edge temp_edge;

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<i; j++)
			{
				temp_w = this->edge_weight(i, j);
				if (temp_w!=NOT_AN_EDGE_UD)
					q.push( {i, j, temp_w} );
			}
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


	void UDirect_Graph_AMatrix::clear()
	{
		for(int i=0; i<n; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		n=0;
	}

	void UDirect_Graph_AMatrix::display()
	{
		std::cout<<"Graf - reprezentacja: macierz sasiedztwa "<<std::endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(matrix[i][j]==NOT_AN_EDGE_UD)
					std::cout<< std::setw(4)<<std::right <<" . " ;// << " ";
				else
					std::cout<< std::setw(4)<<std::right <<matrix[i][j] ;// << " ";
			}
			std::cout<<std::endl;
		}
	}
