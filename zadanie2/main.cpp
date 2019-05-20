#include <iostream>
#include <climits>
#include "src/Adjacency_List.h"
#include "src/UDirect_Graph_AList.h"
#include "src/Disjoint_Set.h"
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

    Disjoint_Set stt{10};

    cout<< stt.find(0)<<endl;
    cout<< stt.find(1)<<endl;
    cout<< stt.find(9)<<endl;

    stt.join(0,1);
    stt.join(0,9);
    stt.join(9,2);
    cout<< 0<<stt.find(0)<<endl;
    cout<< 1<<stt.find(1)<<endl;
    cout<< 2<<stt.find(2)<<endl;
    cout<< 9<<stt.find(9)<<endl;
    stt.join(5,6);
    stt.join(5,7);
    stt.join(6,8);
    cout<< 5<<stt.find(5)<<endl;
    cout<< 6<<stt.find(6)<<endl;
    cout<< 7<<stt.find(7)<<endl;
    cout<< 8<<stt.find(8)<<endl<<endl;

    stt.join(2,5);

    for (int i=0; i<10; i++)
    {
        cout<<i <<' '<<stt.find(i)<<endl;
    }

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

