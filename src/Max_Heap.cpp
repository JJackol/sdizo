#include "Max_Heap.h"
#include <iostream>
#include <iomanip>
#include <fstream>


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
	cr[0] = '*';  cr[1] = '=';
	cl[0] = '+'; cl[1] = '=';
	cp[0] = '|';
	}

	Max_Heap::~Max_Heap()
	{
		delete[] tab;
	}

	void Max_Heap::load_from_file(std::string file_name)
	{
		//clear();
		std::fstream file;
		std::string input;
		int x,s;
		file.open( file_name , std::ios::in );
		if( file.good() == true )
		{
		    file >> input;
		    s=stoi(input);
			while(!file.eof() && s--)
			{
				file>>input;
				x=stoi(input);
				this->push(x);
			}

			//tu operacje na pliku (zapis/odczyt)
			file.close();
		}
	}

	void Max_Heap::heapify()
	{

	}
	void Max_Heap::heapify_up(int index)
	{
		int temp;
		while(index > 0)
		if(tab[index] > tab[parent(index)] )
		{
			temp = tab[index];
			tab[index] = tab[parent(index)];
			tab[parent(index)] = temp;
			index = parent(index);
		}
		else return;

	}
	void Max_Heap::heapify_down(int index)
	{

//		while(index < size)
//		if(tab[index] < tab[left(index)] )
//		{
//			temp = tab[index];
//			tab[index] = tab[parent(index)]
//			tab[parent(index)] = temp;
//		}
//		else return;
		int p = index; //parent
		int l = left(p); //lewy syn ( l+1  -- prawy syn)
		int temp = tab[p];

		while(l<size) //dopóki istnieje przynajmniej jeden syn(lewy)
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

	void Max_Heap::push(int val)
	{
		//realokacja z dwukrotnym nadmiarem jesli zabraknie miejsca w tablicy.
		if(size >= aloc_size)
		{
			aloc_size *= 2;
			int* new_tab = new int[aloc_size];
			copy(tab, new_tab, size);
			delete tab;
			tab = new_tab;
		}
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
		if(size == 0)
			return;
		size--;

		tab[0] = tab[size];
		heapify_down(0);
	}

	void Max_Heap::remove_key(int val)
	{
		int index = 0;
		while(index < size)
		{
			if(tab[index] == val)
			{
				size--;
				tab[index] = tab[size];
				if(tab[index] > tab[parent(index)] )
					heapify_up(index);
				else
					heapify_down(index);
			}
			else index++;
		}

	}


	bool Max_Heap::search_for(int const val)
	{
		int index = 0;
		while(index < size)
		{
			if(tab[index] == val)	return true;
			index++;
		}
		return false;
	}

	void Max_Heap::print()
	{
		std::cout << std::endl;
		print_tree();
		std::cout <<"rozmiar: "<<size<< std::endl;
		std::cout << std::endl;
	}
	// Procedura wypisuje drzewo
	//--------------------------
	//słabo sformatowana funkcja wypisująca drzewo (początkowo wystarczy do testowania).
	//przechodzi przez drzewo in-order "od prawej";
	void Max_Heap::print_tree(std::string sp, std::string sn, int v)
	{
		std::string s;

		if(v < size)
		{
			s = sp;
			if(sn == cr )
				s[s.length() - 2] = ' ';
			print_tree(s + cp, cr, 2 * v + 2);

			s = s.substr(0,sp.length()-2);

			std::cout << s << sn << tab[v] << std::endl;

			s = sp;
			if(sn == cl)
				s[s.length() - 2] = ' ';
			print_tree(s + cp, cl, 2 * v + 1);
		}
	}
		//pomocnicze f.
	void Max_Heap::generate_heap(unsigned int _size, int _max, int _min)
	{
		_max = _max - _min + 1;
		for (unsigned int i=0; i<_size; i++)
			push( rand() % _max - _min);
	}

	void Max_Heap::copy(int* from, int* to, unsigned int size)
	{
		for(unsigned int i=0; i<size; i++)
		{
			to[i] = from[i];
		}
	}
	void Max_Heap::clear()
	{
		delete tab;
		aloc_size = 1024;
		tab = new int [aloc_size];
		size = 0;
	}


