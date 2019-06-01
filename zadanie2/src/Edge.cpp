#include "Edge.h"
#include <iostream>

	Edge::~Edge()
	{
		//dtor
	}

	Edge::Edge(const Edge& other)
	{
		source = other.source;
		dest = other.dest;
		weight = other.weight;
	}

	Edge& Edge::operator=(const Edge& rhs)
	{
		if (this == &rhs) return *this; // handle self assignment

		source = rhs.source;
		dest = rhs.dest;
		weight = rhs.weight;

		return *this;
	}

	void Edge::display()
	{
		std::cout<<'['<<'('<<source<<", "<<dest<<')'<< "w: "<<weight<<']'<< std::endl;
	}

	bool operator< (const Edge& e1, const Edge& e2)
	{
		return e1.weight<e2.weight;
	}
