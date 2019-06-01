#ifndef UDIRECT_GRAPH_AMATRIX_H
#define UDIRECT_GRAPH_AMATRIX_H
#include <climits>
#include <Edge_List.h>

constexpr int NOT_AN_EDGE_UD = INT_MAX;
class UDirect_Graph_AMatrix
{
		int** matrix;
		int n;
		friend class UDirect_Graph_AList;
	public:
		UDirect_Graph_AMatrix(int _n);
		virtual ~UDirect_Graph_AMatrix();
		int get_n(){return n;};

		int edge_weight(int source, int dest);

		bool add_edge(int source, int dest, int w);
		//bool remove_edge(source, dest)
		void gen(int _n, double proc, int min_w=0, int max_w=10);
		void make_complete(int min_w, int max_w);

		Edge_List Kruskal();
		Edge_List Prim();

		void clear();
		void display();

	protected:

	private:
};

#endif // UDIRECT_GRAPH_AMATRIX_H
