#pragma once
#include <string>

class Max_Heap
{
	int* tab=nullptr;
	unsigned int aloc_size=1024;
	int size = 0;

	std::string cr,cl,cp;

	public:
		Max_Heap();
		virtual ~Max_Heap();
		void load_from_file(std::string file_name);

		void heapify();
		void heapify_up(int index);
		void heapify_down(int index);
		bool search_for(int val);

		void push(int const val);
		void pop_root();
		void remove_key(int val);

		void print();
		void print_tree(std::string sp="", std::string sn="", int v=0);
		void generate_heap(unsigned int _size = 16, int _max=999, int _min=0);
		void clear();
	protected:

		int parent(int i) { return (i-1)/2; }
		int left(int i) { return (2*i + 1); }
		int right(int i) { return (2*i + 2); }


		void copy(int* from, int* to, unsigned int size);
	private:

};


