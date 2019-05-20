#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H


class Disjoint_Set
{
    int n;
    int* parents;
    public:
        Disjoint_Set(int _n);
        virtual ~Disjoint_Set();

        int find(int x);
        void join(int x, int y);

    protected:

    private:
};

#endif // DISJOINT_SET_H
