#include <iostream>
#include "SL_List.h"

int main(int argc, char** argv)
{
	SL_List list;
	list.insert_end(5);
	std::cout<<argc<< std::endl;
	return 0;
}

