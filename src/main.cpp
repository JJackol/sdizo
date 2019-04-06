#include <iostream>
#include "main_list.h"
#include "main_array.h"
#include "main_heap.h"
#include "DArray.h"
#include "menu.h"
//#include "Timer.h"
#include "testy.h"

#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    cout << "Program: Struktury" << endl;

    srand(time(NULL));
    menu();

//	test_heap_rosnace();
//	test_heap_malejace();
//	test_list_random();
//	test_array_rand();
//	test_array_zera();
//	test_list_random();
//	test_heap_rand();
//	test_heap_zera();
	//test_array();

//	main_list(argc, argv);
//	main_array(argc, argv);
//	DArray tab;
//	tab.load_from_file("numbers.txt");
//	tab.generate_arr();
//	tab.print();

    cout << argv[0] << endl;



    return 0;
}
