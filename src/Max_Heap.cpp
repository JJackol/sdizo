#include "Max_Heap.h"
#include <iostream>
#include <iomanip>


//enum Edges
//{
//
//};


	Max_Heap::Max_Heap()
	{
		tab = new int[aloc_size];

	// ustawiamy łańcuchy znakowe, ponieważ nie wszystkie edytory pozwalają
	// wstawiać znaki konsoli do tworzenia ramek.
	// cr = +--
	//      |

	// cl = |
	//      +--

	// cp = |
	//      |
//	cr = cl = cp = "  ";
//	cr[0] = 218; cr[1] = 196;
//	cl[0] = 192; cl[1] = 196;
//	cp[0] = 179;

	cr = cl = cp = "  ";
	cr[0] = '.';  cr[1] = '-';
	cl[0] = '.'; cl[1] = '_';
	cp[0] = '|';
	}

	Max_Heap::~Max_Heap()
	{
		delete[] tab;
	}

	void Max_Heap::push(int val)
	{
		int p, i;
		i = size++;

		p = (i-1) / 2;
		while(val > tab[p] && i>0)
		{
			tab[i] = tab[p];
			i = p;
			p = (p-1) / 2;
		}
		tab[i] = val;


	}


	void Max_Heap::pop_root()
	{
		if(--size == 0)
			return;

		int temp;
		temp = tab[size];//temp

		int p = 0;
		int l = 1;


		while(l<size)
		{
			if( l+1 <size && tab[l] < tab[l+1])//wybierz wiekszego syna, o ile istnieje
			{
				l++;
			}

			if( temp < tab[l]) //half-swap, jesli syn wiekszy od ojca
			{
				tab[p] = tab[l];
			}
			else //temp zastepuje aktualny wierzchołek
			{
				tab[p] = temp;
				temp = tab[l];

			}
			p = l;
			l = 2*l + 1;
			tab[p] = temp;
		}
	}


// Procedura wypisuje drzewo
//--------------------------
//słabo sformatowana funkcja wypisująca drzewo (początkowo wystarczy do testowania).
//przechodzi przez drzewo in-order;
void Max_Heap::print(std::string sp, std::string sn, int v)
{
	std::string s;

	if(v < size)
	{
		s = sp;
		if(sn == cr)
			s[s.length() - 2] = ' ';
		print(s + cp, cr, 2 * v + 2);

		s = s.substr(0,sp.length()-2);

		std::cout << s << sn << tab[v] << std::endl;

		s = sp;
		if(sn == cl)
			s[s.length() - 2] = ' ';
		print(s + cp, cl, 2 * v + 1);
	}
}
