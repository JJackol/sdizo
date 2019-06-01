#ifndef EDGE_H
#define EDGE_H
#include <climits>

class Edge
{
	public:
		static constexpr int NOT_AN_EDGE = INT_MAX;

		int source, dest;
		int weight;
		Edge(int _source=0, int _dest=0, int _weight=0)
			:source{_source}, dest{_dest}, weight{_weight}{}

		virtual ~Edge();
		Edge(const Edge& other);
		Edge& operator=(const Edge& other);

		void display();
		friend bool operator< (const Edge& e1, const Edge& e2);
};



#endif // EDGE_H
