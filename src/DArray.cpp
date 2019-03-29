#include "DArray.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>


	DArray::DArray(unsigned int _aloc_size) : aloc_size(_aloc_size), size(0)
	{
		unsigned int i=1;
		while(i<aloc_size)
			i*=2;
		aloc_size=i;
		tab = new int[aloc_size];
	}

	DArray::~DArray()
	{
		delete[] tab;
	}

	DArray::DArray(const DArray& other) : aloc_size(other.aloc_size), size(other.size)
	{
		tab = new int[aloc_size];
		copy(other.tab, tab, size);
	}

	DArray& DArray::operator=(const DArray& other)
	{
		if (this == &other) return *this; // handle self assignment

		aloc_size = other.aloc_size;
		size = other.size;
		tab = new int[aloc_size];
		copy(other.tab, tab, size);

		return *this;
	}
	void DArray::load_from_file(std::string file_name)
	{
		clear();
		std::fstream file;
		std::string input;
		int x;
		file.open( file_name , std::ios::in );
		if( file.good() == true )
		{
			while(!file.eof())
			{
				file>>input;
				x=stoi(input);
				this->insert_end(x);
			}

			//tu operacje na pliku (zapis/odczyt)
			file.close();
		}
	}

	void DArray::generate_arr(unsigned int _size)
	{
		clear();
		for(unsigned int i = 0; i<_size; i++)
			insert_end(rand()%1000);

	}

	void DArray::print()
	{

	    for (unsigned int i=0; i<size; i++)
			std::cout<< std::setw(4)<<std::left <<tab[i] << " ";
	    std::cout<<std::endl;
	}

	bool DArray::is_Empty()
	{
		return !size;
	}
	void DArray::insert_end(int val)
	{
		if(size < aloc_size){
			tab[size] = val;
			size++;
		}
		else
		{
			int* new_tab = new int[aloc_size = 2*aloc_size];
			copy(tab, new_tab, size);
			delete[] tab;
			tab = new_tab;
			tab[size] = val;
			size++;
		}
	}
	void DArray::insert_beg(int val)
	{
		if(size < aloc_size) // jeśli zmieści się w zaalokowanej pamięci
		{
			copy_inv(tab, tab+1, size); //przesuń elementy
			tab[0] = val;
			size++;
		}
		else // realokacja
		{
			int* new_tab = new int[aloc_size = 2*aloc_size];
			copy_inv(tab, new_tab+1, size);
			delete[] tab;
			tab = new_tab;
			tab[0] = val;
			size++;
		}
	}
	void DArray::insert(unsigned int index, int val)
	{
		if(index>size)
		{
			std::cout<< "out of bounds, can't insert"<<std::endl;
			return;
		}

		if(size < aloc_size)
		{
			copy_inv(tab+index, tab+index+1, size); //rozsuń tablicę
			tab[index] = val;
			size++;
		}
		else
		{
			int* new_tab = new int[aloc_size = 2*aloc_size];
			copy(tab, new_tab, index);
			copy(tab+index, new_tab+index+1, size-index);
			delete[] tab;
			tab = new_tab;
			tab[index] = val;
			size++;
		}
	}

	int DArray::at(unsigned int index)
	{
		if(index<size )	//&& index>=0) //dla uint zawsze prawdziwy
			return tab[index];
		std::cout<< "out of bounds"<<std::endl;
		return -1;

	}
	int DArray::find(int val)
	{
		for(unsigned int i=0; i<size; i++)
		{
			if(tab[i] == val)
				return i;
		}

		return -1;
	}
	void DArray::remove_at(unsigned int index)
	{
		if(index<size ) //&& index>=0) //dla uint zawsze prawdziwy
		{
			copy(tab+index+1, tab+index, size-index-1);
			size--;
		}
		else
		{
			std::cerr<< "out of bounds, can't delete"<<std::endl;
		}

	}



	void DArray::remove_end()
	{
		if(is_Empty())
			return;
		size--;
	}
	void DArray::remove_beg()
	{
		if(is_Empty())
			return;
		copy(tab+1, tab, --size);
	}

	void DArray::clear()
	{
		delete[] tab;
		aloc_size=1;
		tab= new int[aloc_size];
		size=0;
	}

	//pomocnicze f.
	void DArray::copy(int* from, int* to, unsigned int size)
	{
		for(unsigned int i=0; i<size; i++)
		{
			to[i] = from[i];
		}
	}
	void DArray::copy_inv(int* from, int* to, unsigned int size)
	{
		//   \/ celowo int ze znakiem,
		for(int i=size-1; i>=0; i--)
		{
			to[i] = from[i];
		}
	}
