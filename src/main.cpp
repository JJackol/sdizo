#include <iostream>
#include "main_list.h"
#include "main_array.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Program: Struktury" << endl;
    int x= -1;
    unsigned int u=1;
    cout << (x<u) << endl;

    main_list(argc, argv);
    main_array(argc, argv);

    return 0;
}
