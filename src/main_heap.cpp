#include <iostream>
#include "SL_List.h"
#include "main_heap.h"
#include "Max_Heap.h"

int main_heap(int argc, char** argv)
{
	std::cout << std::endl<< std::endl
	<< "	PodProgram: Sterta" << std::endl;

	Max_Heap kopiec;

	kopiec.push(1);
	kopiec.push(2);
	kopiec.push(3);
	kopiec.push(34);
	kopiec.push(3);
	kopiec.push(33);
	kopiec.push(6);
	kopiec.push(8);
	kopiec.push(6);
	kopiec.push(99);
	kopiec.push(99);
	kopiec.push(99);
	kopiec.push(99);
	kopiec.push(99);
	kopiec.push(99);
	kopiec.push(56);
	kopiec.push(13);
	kopiec.push(17);
	kopiec.push(7);
	kopiec.push(-1);

	kopiec.print();

	std::cout << std::endl;
	std::cout <<"find 8: "<< kopiec.search_for(8) << std::endl;
	std::cout <<"find 34: "<< kopiec.search_for(34) << std::endl;
	std::cout <<"find 0: "<< kopiec.search_for(0) << std::endl;
	std::cout <<"find 1111: "<< kopiec.search_for(1111) << std::endl;
	std::cout <<"find 99: "<< kopiec.search_for(99) << std::endl;
	std::cout <<"remove  3: "<< std::endl;
	kopiec.remove_key(3) ;
	std::cout <<"remove  99: "<< std::endl;
	kopiec.remove_key(99) ;

	std::cout << std::endl;
	kopiec.pop_root();
	kopiec.print();
	std::cout << std::endl;
	kopiec.pop_root();
	kopiec.print();




	//std::cout<<argc<< std::endl;
	return 0;
}

