#include "Priority_Queue.h"


Priority_Queue::Priority_Queue(int aloc_size): aloc_size{aloc_size}, _size{0}
{
	tab = new Edge[aloc_size];

}

Priority_Queue::~Priority_Queue()
{
	delete[] tab;
}


void Priority_Queue::push(Edge e)
{
	int p, i;
	i = _size++;

	p = (i-1) / 2;
	while(e < tab[p] && i>0)
	{
		tab[i] = tab[p];
		i = p;
		p = (p-1) / 2;
	}
	tab[i] = e;
}

Edge Priority_Queue::pop()
{
		if(_size == 0)
			return {0,0, Edge::NOT_AN_EDGE};
		_size--;
		Edge ret{tab[0]};
		tab[0] = tab[_size];
		heapify_down(0);
		return ret;
}

void Priority_Queue::decrease_key(Edge e, int new_source, int new_key)
{
		int index = 0;
		while(index < _size)
		{
			if(tab[index].weight == e.weight && tab[index].dest == e.dest)
			{
				tab[index].weight = new_key;
				tab[index].source = new_source;
				heapify_up(index);
				return;
			}
			index++;
		}

}

void Priority_Queue::heapify_up(int index)
{
		Edge temp;
		while(index > 0)
			if(tab[index] < tab[(index-1)/2] )
			{
				temp = tab[index];
				tab[index] = tab[(index-1)/2];
				tab[(index-1)/2] = temp;
				index = (index-1)/2;
			}
			else return;
}

void Priority_Queue::heapify_down(int index)
{
		int p = index; //parent
		int l = 2*p+1; //lewy syn ( l+1  -- prawy syn)
		Edge temp = tab[p];

		while(l<_size) //dopóki istnieje przynajmniej jeden syn(lewy)
		{
			if( l+1 <_size && tab[l+1] < tab[l])//wybierz mniejszego syna, o ile istnieje
			{
				l++;
			}

			if( tab[l] < temp  ) //half-swap, jesli syn wiekszy od ojca
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
	void Priority_Queue::display()
	{
		for(int i = 0; i<_size ; i++)
			tab[i].display();
	}
