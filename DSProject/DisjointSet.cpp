#include "DisjointSet.h"

DSnode::DSnode(Coordinate* co)
{
	rank = 0;
	parent = this;
	coord = co;
}

DSnode* DSnode::FIND(DSnode* tar)
{
	if (tar == tar->parent)
		return tar;
	return tar->parent = FIND(tar->parent);
}

void DSnode::UNION(DSnode* a, DSnode* b)
{
	a = FIND(a);
	b = FIND(b);
	int ranka = a->rank;
	int rankb = b->rank;
	if (ranka == rankb)
	{
		a->rank++;
		b->parent = a;
		return;
	}
	DSnode* boss = ranka > rankb ? a : b;
	DSnode* under = ranka > rankb ? b : a;
	under->parent = boss;
	return;
}