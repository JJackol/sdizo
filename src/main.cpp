#include <iostream>
#include "main_list.h"
#include "main_array.h"
#include "DArray.h"
#include "menu.h"


using namespace std;

int main(int argc, char** argv)
{
    //main_list(argc, argv);
    //main_array(argc, argv);
	DArray tab;
	//tab.load_from_file("numbers.txt");
	tab.generate_arr();
	tab.print();

    cout << argv[0] << endl;
    cout << "Program: Struktury" << endl;
    menu();


    return 0;
}
