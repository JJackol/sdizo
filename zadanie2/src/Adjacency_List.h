#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include <climits>

constexpr int NOT_AN_EDGE = INT_MAX;
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
		friend class UDirect_Graph_AList;
		Node* head;

	public:
		Adjacency_List();
		virtual ~Adjacency_List();
		void insert_beg(int _dest, int _weight);
		void remove_val(int dest);
		int get_weight(int dest);
		int get_size();

		void clear();
		void print();

};

#endif // ADJACENCY_LIST_H
