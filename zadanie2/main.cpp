#include <iostream>
#include <climits>
#include "src/Adjacency_List.h"
#include "src/UDirect_Graph_AList.h"
#include "src/Direct_Graph_AList.h"
#include "src/UDirect_Graph_AMatrix.h"
#include "src/Direct_Graph_AMatrix.h"
#include "src/Disjoint_Set.h"
#include "src/Edge_List.h"
#include "src/Priority_Queue.h"
#include <ctime>
#include <cstdlib>

using namespace std;

constexpr int MIN_INT = INT_MIN;
constexpr int MAX_INT = INT_MAX;

void test1();
void test2();
void test3();
void testEdgeList();
void testPrioQ();
void testKruskal();
void testPrim();
void testDirectList();


int main()
{
	srand(time(NULL));

	//test2();
	//testKruskal();
	//testPrim();
	//testPrioQ();
	testDirectList();

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

void test3()
{
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

    UDirect_Graph_AMatrix graf{0};
    graf.gen(1000,0.99,0,20);
    graf.display();

    UDirect_Graph_AList graf2{graf};
    graf2.display();

}

void testEdgeList()
{
	Edge_List elist;
	elist.insert_beg({2,4,6});
	elist.insert_beg({2,4,6});
	elist.display();
	Edge ed[2] = { {1,2,3}, {4,5,6} };
	//Edge* eg = new Edge[2];
	cout<< sizeof(ed)<<endl;
	cout<< sizeof(elist)<<endl;
	cout<< sizeof(Edge)<<endl;
	cout<< sizeof(ENode)<<endl;

}

void testPrioQ()
{
	Priority_Queue q{16};
	q.push({1,2,3});
	q.push({7,7,6});
	q.push({0,1,-3});
	q.push({0,1,10});
	q.push({0,1,0});
	q.push({0,1,8});
	q.push({0,1,6});
	q.push({0,1,5});
	q.push({0,1,3});
	q.push({0,1,4});

	q.display();

	cout<<"pop"<<endl;
	q.pop().display();
	cout<<"pop"<<endl;
	q.display();

	cout<<"pop"<<endl;
	q.decrease_key({0,1,10},100, -13);
	cout<<"pop"<<endl;
	q.display();


}

void testPrim()
{
	UDirect_Graph_AMatrix mgraf{10};
	mgraf.gen(10, 50, 1, 100);
	mgraf.display();
	mgraf.Prim().display();
	mgraf.Kruskal().display();
	mgraf.display();

}

void testKruskal()
{
	UDirect_Graph_AList lgraf{10};
	lgraf.gen(10, 10, 1, 100);
	lgraf.display();
	//lgraf.Kruskal().display();

	lgraf.gen(10, 90, 1, 100);
	lgraf.display();
	lgraf.Prim().display();
	lgraf.Kruskal().display();

	lgraf.load_from_file("dane_mst.txt");
	lgraf.display();
	lgraf.Prim().display();
	lgraf.Kruskal().display();

	lgraf.load_from_file("dane_mst2.txt");
	lgraf.display();
	lgraf.Prim().display();
	lgraf.Kruskal().display();

}

void testDirectList()
{
	int N = 10;
	int prev[N];
	int dist[N];

	Direct_Graph_AMatrix dmatrix{0};
	dmatrix.gen(N, 50);
	dmatrix.display();
	dmatrix.Dijkstra(0, dist, prev);

	for(int i=0;i<N; i++)
	{
		cout<<i<<' '<<prev[i]<<' '<<dist[i]<<endl;
	}


	Direct_Graph_AList dlist{dmatrix};
	//dlist.gen(10, 50);
	dlist.display();
	dlist.Dijkstra(0, dist, prev);

	for(int i=0;i<N; i++)
	{
		cout<<i<<' '<<prev[i]<<' '<<dist[i]<<endl;
	}


}
