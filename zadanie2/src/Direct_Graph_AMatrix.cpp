#include "Direct_Graph_AMatrix.h"
#include "Disjoint_Set.h"
#include "Priority_Queue.h"
#include "Edge.h"
#include "Edge.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>


	Direct_Graph_AMatrix::Direct_Graph_AMatrix(int _n): n{_n}
	{
		matrix = new int*[n];
		for(int i=0; i<n; i++)
		{
			matrix[i] = new int[n];
			for(int k=0; k<n; k++)
				matrix[i][k] = Edge::NOT_AN_EDGE;
		}
	}

	Direct_Graph_AMatrix::~Direct_Graph_AMatrix()
	{
		this->clear();
	}

	int Direct_Graph_AMatrix::edge_weight(int source, int dest)
	{
		return matrix[source][dest];
	}

	bool Direct_Graph_AMatrix::add_edge(int source, int dest, int w)
	{
		matrix[source][dest] = w;
		return true;
	}

	//result in arrays passed as arguments
	// arrays needs to be allocated before calling this func.
	void Direct_Graph_AMatrix::Dijkstra(int start, int* dist, int* prev)
	{
		Priority_Queue q{n};
		Edge temp_edge;

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

			for(k=0; k<n; k++)
			{
					if (	edge_weight(i, k) != Edge::NOT_AN_EDGE
							&& dist[k]  > dist[i]+edge_weight(i, k)
						)
					{
						q.decrease_key({i, k, dist[k]}, i, dist[i]+edge_weight(i, k) );
						prev[k] = i;
						dist[k] = dist[i]+edge_weight(i, k);
					}
				}
		}
		return;
	}

	//result in arrays passed as arguments
	// arrays needs to be allocated before calling this func.
	//
	//returns true if negative cycle found
	bool Direct_Graph_AMatrix::BellmanFord(int start, int* dist, int* prev)
	{
		bool flag;
		for(int i=0; i<n; i++)
		{
			dist[i] = Edge::NOT_AN_EDGE;
			prev[i] = -1;
		}
		dist[start] = 0;
		prev[start] = start;

		for(int i=0; i<n; i++)
		{
			flag = false;
			for(int i=0; i<n; i++)
			{
				for(int k=0; k<n; k++)
				{

					if (	edge_weight(i, k) != Edge::NOT_AN_EDGE
							&& dist[k]  > (long long)dist[i]+edge_weight(i, k)
						)
					{
						prev[k] = i;
						dist[k] = dist[i]+edge_weight(i, k) ;
						flag = true;
					}

				}
			}
		}
		return flag;
	}

	void Direct_Graph_AMatrix::gen(int _n, double proc, int min_w, int max_w)
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
					matrix[i][k] = Edge::NOT_AN_EDGE;
			}

			int max_number_of_edges = (n*(n-1));
			int number_of_edges = ceil(max_number_of_edges*proc*0.01);

			int dest, source;
			int i_weight;
			int i;
			Disjoint_Set d_set{n};
			//pętla generująca drzewo rozpinające
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
						&& matrix[source][dest] == Edge::NOT_AN_EDGE
					)
				{
					i_weight = rand()% (max_w-min_w+1) + min_w ;
					add_edge(source , dest, i_weight);
					i_weight = rand()% (max_w-min_w+1) + min_w ;
					add_edge(dest, source,  i_weight);
					d_set.join(source, dest);
					i++;
					i++;
				}
			}

			//generuje resztę krawędzi
			while(i<number_of_edges)
			{
				source = rand()%n;
				dest = rand()%n;
				if(source!=dest && matrix[source][dest]==Edge::NOT_AN_EDGE)
				{
					i_weight = rand()% (max_w-min_w+1) + min_w ;
					add_edge(source, dest, i_weight);
					i++;
				}
			}
		}
	}

	void Direct_Graph_AMatrix::make_complete(int min_w, int max_w)
	{
		for(int i=0; i<n; i++)
		{
			for(int k=0; k<n; k++)
				if(i!=k)
					matrix[i][k] = rand()% (max_w-min_w+1) - min_w ;
		}
	}




	void Direct_Graph_AMatrix::clear()
	{
		for(int i=0; i<n; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		n=0;
	}

	int Direct_Graph_AMatrix::load_from_file(std::string f_name)
	{
		//
		//	TODO	//////////////////
		//

		std::fstream file;
		std::string input;
		int _n, _k, start;
		int source, dest, weight;
		file.open( f_name , std::ios::in );
		if( file.good() == true )
		{
		    file >> _k >> _n >> start;
			clear();
		    n = _n;
			matrix = new int*[n];
		    for(int i=0; i<n; i++)
			{
				matrix[i] = new int[n];
				for(int j=0; j<n; j++)
				{
					matrix[i][j] = Edge::NOT_AN_EDGE;
				}
			}

			while(!file.eof() && _k--)
			{
				file>>source>>dest>>weight;

				this->add_edge(source, dest, weight);
			}

			//tu operacje na pliku (zapis/odczyt)
			file.close();
		}
		return start;
	}

	void Direct_Graph_AMatrix::display()
	{
		std::cout<<"\nGraf skierowany - reprezentacja: macierz sasiedztwa "<<std::endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(matrix[i][j]==Edge::NOT_AN_EDGE)
					std::cout<< std::setw(4)<<std::right <<" . " ;// << " ";
				else
					std::cout<< std::setw(4)<<std::right <<matrix[i][j] ;// << " ";
			}
			std::cout<<std::endl;
		}
	}
