#include "DArray.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>


	DArray::DArray(unsigned int _size) :  size(_size)
	{
		tab = new int [_size];
//		unsigned int i=1;
//		while(i<aloc_size)
//			i*=2;
//		aloc_size=i;
//		tab = new int[aloc_size];
	}

	DArray::~DArray()
	{
		delete[] tab;
	}

	DArray::DArray(const DArray& other) : size(other.size)
	{
		tab = new int[size];
		copy(other.tab, tab, size);
	}

	DArray& DArray::operator=(const DArray& other)
	{
		if (this == &other) return *this; // handle self assignment

		size = other.size;
		tab = new int[size];
		copy(other.tab, tab, size);

		return *this;
	}
	void DArray::load_from_file(std::string file_name)
	{
		clear();
		std::fstream file;
		std::string input;
		int x,s;
		file.open( file_name , std::ios::in );
		if( file.good() == true )
		{
		    file >> s;
			while(!file.eof() && s--)
			{
				file>>input;
				x=stoi(input);
				this->insert_end(x);
			}

			//tu operacje na pliku (zapis/odczyt)
			file.close();
		}
	}

	void DArray::generate_arr(unsigned int _size, int _max, int _min)
	{
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
		int* new_tab = new int[size+1];
		copy(tab, new_tab, size);
		delete[] tab;
		tab = new_tab;
		tab[size] = val;
		size++;

	}
	void DArray::insert_beg(int val)
	{

		int* new_tab = new int[size+1];
		copy_inv(tab, new_tab+1, size);
		delete[] tab;
		tab = new_tab;
		tab[0] = val;
		size++;

	}
	void DArray::insert(unsigned int index, int val)
	{
		if(index>size)
		{
			std::cout<< "out of bounds, can't insert"<<std::endl;
			return;
		}

		int* new_tab = new int[size+1];
		copy(tab, new_tab, index);
		copy(tab+index, new_tab+index+1, size-index);
		delete[] tab;
		tab = new_tab;
		tab[index] = val;
		size++;

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
		int* new_tab= new int [size];
		copy(tab, new_tab, size);
		delete[] tab;
		tab = new_tab;
	}
	void DArray::remove_beg()
	{
		if(is_Empty())
			return;

		size--;
		int* new_tab= new int [size];
		copy(tab+1, new_tab, size);
		delete[] tab;
		tab = new_tab;
	}

	void DArray::clear()
	{
		delete[] tab;
		size=0;
		tab= new int[size];
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
