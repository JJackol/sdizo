#ifndef DIRECT_GRAPH_AMATRIX_H
#define DIRECT_GRAPH_AMATRIX_H
#include <string>

//constexpr int NOT_AN_EDGE_UD = INT_MAX;
class Direct_Graph_AMatrix
{
		int** matrix;
		int n;
		friend class Direct_Graph_AList;
	public:
		Direct_Graph_AMatrix(int _n);
		virtual ~Direct_Graph_AMatrix();
		int get_n(){return n;};

		int edge_weight(int source, int dest);

		bool add_edge(int source, int dest, int w);

		void Dijkstra(int start, int* dist, int* prev);
		bool BellmanFord(int start, int* dist, int* prev);

		//bool remove_edge(source, dest)
		void gen(int _n, double proc, int min_w=0, int max_w=10);
		void make_complete(int min_w, int max_w);



		void clear();
		int load_from_file(std::string f_name);
		void display();

	protected:

	private:
};

#endif // DIRECT_GRAPH_AMATRIX_H
