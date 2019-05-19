#include "UDirect_Graph_AList.h"
#include <iostream>

	UDirect_Graph_AList::UDirect_Graph_AList(int _n): n{_n}
	{
		a_list = new Adjacency_List[n];
	}

	UDirect_Graph_AList::~UDirect_Graph_AList()
	{
		delete[] a_list;
	}

	void UDirect_Graph_AList::display()
	{
		for(int i=0; i<n; i++)
		{
			std::cout<<"source: "<<i<< "-->-";
			a_list[i].print();
		}
	}
