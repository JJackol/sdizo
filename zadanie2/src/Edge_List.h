#ifndef EDGE_LIST_H
#define EDGE_LIST_H
#include "Edge.h"

class ENode
{

	public:
		Edge e;
		ENode* next;
		ENode(Edge _e, ENode* _next=nullptr)
			:e{_e}, next{_next} {}

};

class Edge_List
{


	ENode* head;
	int _weight;

	public:
		Edge_List();
		Edge_List(const Edge_List& other);
		Edge_List& operator=(const Edge_List&);
		virtual ~Edge_List();
		void insert_beg(Edge );
		//void remove_val(int dest);
		//int get_weight(int, source, int dest);
		int get_size();
		int get_weight();

		void clear();
		void display();
};

#endif // EDGE_LIST_H
