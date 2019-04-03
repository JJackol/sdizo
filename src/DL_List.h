#pragma once

struct Node2
{
	int val=0;
	Node2* next=nullptr;
	Node2* prev=nullptr;
	Node2(int _val=0, Node2* _next=nullptr, Node2* _prev=nullptr )
        : val(_val), next(_next), prev(_prev)
	{};
};

class DL_List
{
	Node2* head = nullptr;
	Node2* tail = nullptr;
	//int my_size = 0;

	public:
	DL_List();
	DL_List(DL_List & L);
	~DL_List();

	void print();
	bool is_Empty();

	void insert_end(int val);
	void insert_beg(int val);
	void insert(int index, int val);

	int at(int index);
	int find(int val);	//zawraca index pierwszego znalezionego elementu

	void remove_at(int index);
	void remove_val(int val);
	void remove_end();
	void remove_beg();

};
