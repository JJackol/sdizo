#include <iostream>
#include "SL_List.h"
#include "main_list.h"

int main_list(int argc, char** argv)
{
	SL_List lista;
	SL_List indexes;
	indexes.insert_end(0);
	indexes.insert_end(1);
	indexes.insert_end(2);
	indexes.insert_end(3);
	indexes.insert_end(4);
	indexes.insert_end(5);
	indexes.insert_end(6);
	indexes.insert_end(7);
	indexes.insert_end(8);
	indexes.insert_end(9);
	indexes.insert_end(10);
	indexes.insert_end(11);
	indexes.insert_end(12);
	indexes.insert_end(13);
	indexes.insert_end(14);
	indexes.insert_end(15);
	indexes.insert_end(16);
	indexes.insert_end(17);


	lista.insert_end(0);
	lista.insert_end(13);
	lista.insert_end(5);
	lista.insert_end(-5);
	lista.insert_end(15);
	lista.insert_end(158);
	lista.insert_end(5);
	lista.insert_end(100);
	lista.insert_end(8);
	lista.insert_end(10);
	lista.insert_end(10);
	lista.insert_end(12);
	lista.insert_end(10);
	lista.insert_end(11);


	indexes.print();
	std::cout<<std::endl;
	lista.print();
    std::cout<<std::endl;


    lista.remove_beg();
    std::cout<<"remove beg"<<std::endl;
	indexes.print();
    std::cout<<std::endl;
    lista.print();
    std::cout<<std::endl;

    std::cout<<"remove at ind 7 and 2"<<std::endl;
    lista.remove_at(7);
    lista.remove_at(2);
	indexes.print();
    std::cout<<std::endl;
    lista.print();
    std::cout<<std::endl;

    std::cout<<"remove end"<<std::endl;
    lista.remove_end();
    std::cout<<std::endl;
	indexes.print();
    lista.print();
    std::cout<<"at 10     : "<<lista.at(10)<<std::endl;
    std::cout<<"at 9     : "<<lista.at(9)<<std::endl;
    std::cout<<"at 8     : "<<lista.at(8)<<std::endl;
    std::cout<<"at 0     : "<<lista.at(0)<<std::endl;
    std::cout<<"at 1     : "<<lista.at(1)<<std::endl;


    std::cout<<"find 10     : "<<lista.find(10)<<std::endl;
    std::cout<<"find 132    : "<<lista.find(132)<<std::endl;
    SL_List lista2;
    std::cout<<"find 132 on empty list : "<<lista2.find(132)<<std::endl;

    std::cout<<"size of Node    : "<<sizeof(Node)<<std::endl;
    std::cout<<"size of Node*   : "<<sizeof(Node*)<<std::endl;
    std::cout<<"size of int     : "<<sizeof(int)<<std::endl;
    std::cout<<"size of Node()  : "<<sizeof(Node())<<std::endl;
    std::cout<<"size of SL_list : "<<sizeof(SL_List)<<std::endl;

	//std::cout<<argc<< std::endl;
	return 0;
}

