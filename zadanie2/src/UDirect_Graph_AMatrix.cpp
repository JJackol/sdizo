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
		}
	}

	UDirect_Graph_AMatrix::~UDirect_Graph_AMatrix()
	{
		this->clear();
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
		}





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
				std::cout<< std::setw(4)<<std::right <<matrix[i][j] ;// << " ";
			}
			std::cout<<std::endl;
		}
	}
