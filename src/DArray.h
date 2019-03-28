#pragma once

class DArray
{
		int* tab = nullptr;
		unsigned int aloc_size;
		unsigned int size;

	public:
		DArray(unsigned int _aloc_size = 0);
		virtual ~DArray();
		DArray(const DArray& other);
		DArray& operator=(const DArray& other);

		void print();
		bool is_Empty();

		void insert_end(int val);
		void insert_beg(int val);
		void insert(int index, int val);

		int at(unsigned int index);
		int find(int val);	//zawraca index pierwszego znalezionego elementu

		void remove_at(unsigned int index);
		void remove_end();
		void remove_beg();

		void clear();

	private:
		void copy(int* from, int* to, unsigned int size); //kopiowanie el. od przodu
		void copy_inv(int* from, int* to, unsigned int size);//kopiowanie el. od tyłu


};
