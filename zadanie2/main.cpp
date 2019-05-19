#include <iostream>
#include <climits>
#include "src/Adjacency_List.h"
#include "src/UDirect_Graph_AList.h"
#include <ctime>
#include <cstdlib>

using namespace std;

constexpr int MIN_INT = INT_MIN;
constexpr int MAX_INT = INT_MAX;

void test1();
void test2();

int main()
{
	srand(time(NULL));
	test2();
    return 0;
}

void test1()
{

	Adjacency_List lista;

	lista.insert_beg(2,1);
	lista.insert_beg(4,2);
	lista.insert_beg(8,3);
	lista.insert_beg(4,3);
	lista.insert_beg(4,7);

	lista.print();

	lista.remove_val(4);
	lista.print();
	cout<< lista.get_weight(2)<<endl;
    cout << "Hello world! size of a: " <<MIN_INT<<' '<<MAX_INT<< ' '<<sizeof(lista)<< endl;

}

void test2()
{
	UDirect_Graph_AList graf{10};
	graf.gen(10,1);
	graf.display();

	cout<< 0<<endl;
    cout << "Hello world! size of a: "<<sizeof(graf)<< endl;

}

