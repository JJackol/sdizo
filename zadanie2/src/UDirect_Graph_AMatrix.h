#ifndef UDIRECT_GRAPH_AMATRIX_H
#define UDIRECT_GRAPH_AMATRIX_H
#include <climits>

constexpr int NOT_AN_EDGE_UD = INT_MAX;
class UDirect_Graph_AMatrix
{
		int** matrix;
		int n;
	public:
		UDirect_Graph_AMatrix(int _n);
		virtual ~UDirect_Graph_AMatrix();

		bool add_edge(int source, int dest, int w);
		void gen(int _n, double proc, int min_w, int max_w);

		void clear();
		void display();

	protected:

	private:
};

#endif // UDIRECT_GRAPH_AMATRIX_H
