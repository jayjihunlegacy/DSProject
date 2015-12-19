#pragma once
#include "Coordinate.h"

class DSnode
{
public:
	DSnode(Coordinate* coord);
	static DSnode* FIND(DSnode*);
	static void UNION(DSnode*,DSnode*);
	static bool comp(const DSnode* t1, const DSnode* t2)
	{
		return Coordinate::comp(t1->coord, t2->coord);
	}

	int rank;
	DSnode* parent;
	Coordinate* coord;
};