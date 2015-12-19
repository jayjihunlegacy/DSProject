#pragma once
#include "Coordinate.h"

#define HYPERPLANE 0
#define POINT 1

class KDnode;
class KDtree;

class KDtree
{
public:
	KDtree(float** points, int dimension, int numOfPoints);
	~KDtree();

	CoordinateSet* getNeighbors(KDnode*, float ep);
	void getNei_recur(KDnode* node, float* tarval, float ep, vector<Coordinate*> *list);
	void print();

	int dim;
	int num;
	KDnode *root;
	Coordinate** points;
};

class KDnode
{
public:
	KDnode(float val,int h);
	KDnode(Coordinate* coord, int h);
	~KDnode();

	void print();

	int depth;
	int type;
	float value;
	Coordinate* coord;
	KDnode* left, *right;
};

void serialNodeKiller(KDnode*);
KDnode* buildKDtree(Coordinate** points, int start, int end, int depth);
int find_medianPos(Coordinate** points, int start, int end, int depth);
int pointcmp(const void*, const void*);