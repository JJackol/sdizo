#pragma once
#include <string>

class Max_Heap
{
	int* tab=nullptr;
	unsigned int aloc_size=128;
	int size = 0;

	std::string cr,cl,cp;

	public:
		Max_Heap();
		virtual ~Max_Heap();
		void load_from_file(std::string file_name);

		void push(int val);
		void pop_root();

		void print(std::string sp="", std::string sn="", int v=0);
	protected:

	private:
};


