#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include <climits>

constexpr int NOT_AN_EDGE = INT_MIN;
class Node
	{
	public:
		int dest;
		int weight;
		Node* next;
		Node(int _dest, int _weight, Node* _next=nullptr)
			:dest{_dest}, weight{_weight}, next{_next} {}
	};

class Adjacency_List
{
		Node* head;

	public:
		Adjacency_List();
		virtual ~Adjacency_List();
		void insert_beg(int _dest, int _weight);
		void remove_val(int dest);
		int get_weight(int dest);

		void print();
		void clear();
};

#endif // ADJACENCY_LIST_H
