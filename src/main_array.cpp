#include <iostream>
#include "SL_List.h"
#include "DArray.h"
#include "main_array.h"

int main_array(int argc, char** argv)
{
	std::cout << std::endl<< std::endl
	<< "	PodProgram: Tablica" << std::endl;
	DArray tablica;
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
//

	tablica.insert_end(0);
	tablica.insert_end(13);
	tablica.insert_end(5);
	tablica.insert_end(-5);
	tablica.insert_end(15);
	tablica.insert_end(158);
	tablica.insert_end(5);
	tablica.insert_end(10);
	tablica.insert_end(12);
	tablica.insert_end(10);
	tablica.insert_end(11);
	//std::cout<<"clear  ************************************************************************"<<std::endl;

	//tablica.clear();

	indexes.print();
	tablica.print();
	//std::cout<<"insert clear  ************************************************************************"<<std::endl;

	std::cout<<std::endl;

	std::cout<<"insert beg 2 razy  ************************************************************************"<<std::endl;
	tablica.insert_beg(-1);
	tablica.insert_beg(121);
	indexes.print();
	tablica.print();
	std::cout<<std::endl;


    tablica.insert(5, 999);
    std::cout<<"insert at 5  ************************************************************************"<<std::endl;
	indexes.print();
    tablica.print();

//    std::cout<< "element o indeksie 6	: " <<tablica.at(6)<<std::endl;
//    std::cout<< "element o indeksie 13	: " <<tablica.at(13)<<std::endl;
//    std::cout<< "element o indeksie 14	: " <<tablica.at(14)<<std::endl;
//    std::cout<< "element o indeksie 0	: " <<tablica.at(0)<<std::endl;
//    std::cout<< "element o indeksie -1	: " <<tablica.at(-1)<<std::endl;
//    std::cout<< "szukaj 5 				: " << tablica.find(5)<<std::endl;
//    std::cout<< "element o indeksie znalezionej piątki 	: " <<tablica.at( tablica.find(5) )<<std::endl;
//
//    std::cout<< "element o indeksie 6	: " <<tablica.at( tablica.find(90) )<<std::endl;

    std::cout<<"remove at ind 7 and 2	**************************************************"<<std::endl;
    tablica.remove_at(-1);
    tablica.remove_at(2);
	indexes.print();
    tablica.print();
    std::cout<<std::endl;

    std::cout<<"remove end	********************************************************"<<std::endl;
    tablica.remove_end();
    std::cout<<std::endl;
	indexes.print();
    tablica.print();

	std::cout<<"remove beg	******************************************************"<<std::endl;
	tablica.remove_beg();
	indexes.print();
    tablica.print();
//    std::cout<<"at 10     : "<<tablica.at(10)<<std::endl;
//    std::cout<<"at 9     : "<<tablica.at(9)<<std::endl;
//    std::cout<<"at 8     : "<<tablica.at(8)<<std::endl;
//    std::cout<<"at 0     : "<<tablica.at(0)<<std::endl;
//    std::cout<<"at 1     : "<<tablica.at(1)<<std::endl;
//
//
    std::cout<<"find 10     : "<<tablica.find(10)<<std::endl;
    std::cout<<"find 132    : "<<tablica.find(132)<<std::endl;
    DArray tablica2;
    std::cout<<"find 132 on empty list : "<<tablica2.find(132)<<std::endl;



	//std::cout<<argc<< std::endl;
	return 0;
}

