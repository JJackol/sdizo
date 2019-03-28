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

	kopiec.printBT();

	std::cout << std::endl;
	kopiec.pop_root();
	kopiec.printBT();




	//std::cout<<argc<< std::endl;
	return 0;
}

