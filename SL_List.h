#pragma once

struct Node
{
	int val=0;
	Node* next=nullptr;
};	

class SL_List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int size=0;

	public:
	SL_List();
	SL_List(SL_List & L);
	~SL_List();	

	bool is_Empty();
	void insert_end(int val);
	void insert_beg(int val);
	void insert(int index, int val);
	int at(int index);
	int find(int val);	//zawraca index pierwszego znalezionego elementu
	void remove_at(int index);
	void remove_val(int val);
	void remove_end(int val);
	void remove_beg(int val);

};
