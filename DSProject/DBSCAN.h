#pragma once
#include "kdtree.h"
#include "DisjointSet.h"
class DBSCAN
{
public:
	DBSCAN(KDtree *kdtree, float epsilon, int minNeighbor);
	~DBSCAN();

	void run();
	int setmake(int seq, KDnode* node);
	void setrun(KDnode* node);

	int num;
	DSnode** set;
	KDtree*kdtree;
	float ep;
	int minNei;
};