#include "Disjoint_Set.h"

Disjoint_Set::Disjoint_Set(int _n): n{_n}
{
    parents = new int[n];
    for(int i=0; i<n; i++)
        parents[i] = -1;
}

Disjoint_Set::~Disjoint_Set()
{
    delete[] parents;
}

int Disjoint_Set::find(int x)
{
    while(parents[x]!=-1)
        x = parents[x];
    return x;
}

void Disjoint_Set::join(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x!=y)
        parents[y] = x;
}




