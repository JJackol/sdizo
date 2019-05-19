#ifndef GRAPH_ALIST_H
#define GRAPH_ALIST_H


class UDirect_Graph_AList
{
	int n; // n= |V|

	class A_List
	{
		class Node
		{
			int dest;
			int weight;
			Node* next;
			Node(int _dest, int _weight, Node* _next=nullptr)
				:dest{_dest}, weight{_weight}, next{_next} {}
		};
		Node* head;

		A_List() :head{nullptr}{}


	};
	public:
		UDirect_Graph_AList();
		virtual ~UDirect_Graph_AList();

	protected:

	private:
};

#endif // GRAPH_ALIST_H
