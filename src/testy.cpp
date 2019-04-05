#include "testy.h"
#include "DArray.h"
#include "DL_List.h"
#include "Max_Heap.h"
#include "sstream"
#include "fstream"
#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std::chrono;

void test_array_rand()
{
	std::ofstream out_file( "results/tab/tab_add_r_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;

	DArray tablica;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	high_resolution_clock::time_point t3;
	high_resolution_clock::time_point t4;

	for(int j = 0; j<100 ; j++)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			tablica.insert_end( rand() );
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();

	out_file.open("results/tab/tab_rem_r_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;
	for(int j = 100; j>0 ; j--)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			tablica.remove_end();
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();
}
void test_array_zera()
{
	std::ofstream out_file( "results/tab/tab_add_zera_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;

	DArray tablica;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;


	for(int j = 0; j<100 ; j++)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			tablica.insert_end( 0 );
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}


	out_file.close();
}
void test_list_random()
{
	std::ofstream out_file( "results/list/list_add_r_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;

	DL_List lista;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	high_resolution_clock::time_point t3;
	high_resolution_clock::time_point t4;

	for(int j = 0; j<1000 ; j++)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			lista.insert_end( rand() );
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();

	out_file.open("results/list/list_rem_r_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;
		for(int j = 1000; j>0 ; j--)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			lista.remove_end();
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}


	out_file.close();
}
void test_heap_rand()
{
	std::ofstream out_file( "results/heap/heap_add_r_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;

	Max_Heap heap;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	for(int j = 0; j<1000 ; j++)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			heap.push( rand() );
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();

	out_file.open("results/heap/heap_rem_r_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;
		for(int j = 1000; j>0 ; j--)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			heap.pop_root();
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();
}

void test_heap_zera()
{
	std::ofstream out_file( "results/heap/heap_add_z_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;

	Max_Heap heap;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;

	for(int j = 0; j<1000 ; j++)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			heap.push( 0 );
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();

	out_file.open("results/heap/heap_rem_z_1000_el.txt", std::ios::out);
	if( !out_file.good())
		return;
		for(int j = 1000; j>0 ; j--)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<1000; i++)
		{
			heap.pop_root();
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*1000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();
}
void test_heap_malejace()
{
	std::ofstream out_file( "results/heap/heap_add_mal_100,000_el.txt", std::ios::out);
	if( !out_file.good())
		return;

	Max_Heap heap;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	int val = 0x7fffffff;
	for(int j = 0; j<1000 ; j++)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<100000; i++)
		{
			heap.push( val-- );
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*100000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();

	out_file.open("results/heap/heap_rem_mal_100,000_el.txt", std::ios::out);
	if( !out_file.good())
		return;
		for(int j = 1000; j>0 ; j--)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<100000; i++)
		{
			heap.pop_root();
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*100000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();
}

void test_heap_rosnace()
{
	std::ofstream out_file( "results/heap/heap_add_rand_100,000_el.txt", std::ios::out);
	if( !out_file.good())
		return;

	Max_Heap heap;

	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	//int val = 0x80000000;
	for(int j = 0; j<1000 ; j++)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<100000; i++)
		{
			heap.push( rand() );
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*100000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();

	out_file.open("results/heap/heap_rem_rand_100,000_el.txt", std::ios::out);
	if( !out_file.good())
		return;
		for(int j = 1000; j>0 ; j--)
	{
		t1 = high_resolution_clock::now();
		for(int i=0; i<100000; i++)
		{
			heap.pop_root();
		}
		//mierzona operacja
		t2 = high_resolution_clock::now();
		duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);
		out_file<<(j)*100000<<","<<std::fixed<<std::setprecision (12) << pomiar.count()<<std::endl;
	}
	out_file.close();
}
/*

	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;


	t1 = std::chrono::high_resolution_clock::now();

	//mierzona operacja

	t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> pomiar = duration_cast<duration<double>>(t2 - t1);

	std::cout <<std::fixed<<std::setprecision (12) << pomiar.count() << std::endl;


*/
