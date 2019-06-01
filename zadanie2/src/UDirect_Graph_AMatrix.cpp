#include "UDirect_Graph_AMatrix.h"
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
			for(int k=0; k<n; k++)
				matrix[i] = new int[n];
		}

		if(false)
		{
			this->make_complete(min_w, max_w);

		}
		else
		{
			for(int i=0; i<n; i++)
			{
				for(int k=0; k<n; k++)
					matrix[i][k] = NOT_AN_EDGE_UD;
			}

			int max_number_of_edges = (n*(n-1))/2;

			int number_of_edges = ceil(max_number_of_edges*proc);
			std::cout<<number_of_edges<<std::endl;
			int join, dest, source;
			int i_weight;
			int i;
			//pętla generująca drzewo rozpinające
			//dołącza kolejne wierzchołki do już istniejącego drzewa
			for (i = 1; i<n; i++)
			{
				join = rand()%i;
				i_weight = rand()% (max_w-min_w+1) - min_w ;
				add_edge(join, i, i_weight);
			}

			std::cout<<number_of_edges<<std::endl;
			while(i<=number_of_edges)
			{

				source = rand()%n;
				dest = rand()%n;
				if(source!=dest && matrix[source][dest]==NOT_AN_EDGE_UD)
				{
					std::cout<<number_of_edges<<std::endl;
					i_weight = rand()% (max_w-min_w+1) - min_w ;
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

//	KRUSKAL(G):
//1 A = ∅
//2 foreach v ∈ G.V:
//3    MAKE-SET(v)
//4 foreach (u, v) in G.E ordered by weight(u, v), increasing:
//5    if FIND-SET(u) ≠ FIND-SET(v):
//6       A = A ∪ {(u, v)}
//7       UNION(FIND-SET(u), FIND-SET(v))
//8 return A

	Edge_List UDirect_Graph_AMatrix::Kruskal()
	{
		return Edge_List();
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
