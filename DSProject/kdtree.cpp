#include "kdtree.h"
#include <vector>
#include <cmath>
int depthForSort;

extern KDnode* buildKDtree(float**, int, int, int);

KDtree::KDtree(float** points, int dimension, int numOfPoints)
{
	dim = dimension;
	num = numOfPoints;
	this->points = (Coordinate**)malloc(sizeof(Coordinate*)*num);
	for (int i = 0; i < numOfPoints; i++)
		this->points[i] = new Coordinate(points[i], i, dimension);
	root = buildKDtree(this->points, 0, num, 0);
}

void KDtree::print()
{
	root->print();
}

CoordinateSet* KDtree::getNeighbors(KDnode* node, float ep)
{

	vector<Coordinate*>* points = new vector<Coordinate*>();
	getNei_recur(root, node->coord->values, ep, points);
	return new CoordinateSet(points);
}

void KDtree::getNei_recur(KDnode* node, float* tarval, float ep, vector<Coordinate*> *list)
{
	//printf("GETNEI called\n");
	if (!node)
		return;
	if (node->type == HYPERPLANE)
	{
		float minv = tarval[(node->height) % dim] - ep;
		float maxv = tarval[(node->height) % dim] + ep;
		float val = node->value;
		if (minv <= val)
			getNei_recur(node->left, tarval, ep, list);
		if (val < maxv)
			getNei_recur(node->right, tarval, ep, list);
		return;
	}

	for (int i = 0; i < dim; i++)
	{
		float val = node->coord->val(i);
		float minv = tarval[i] - ep;
		float maxv = tarval[i] + ep;
		if (val < minv || maxv < val)
			return;
	}
	bool issame = true;
	float dis_square = 0;
	for (int i = 0; i < dim; i++)
	{
		float aroundvalue = node->coord->val(i);
		float basevalue = tarval[i];
		float dif = aroundvalue - basevalue;
		if (basevalue != aroundvalue)
			issame = false;
		dis_square += dif*dif;
	}

	if (issame)
		return;
	float distance = sqrt(dis_square);
	if (distance > ep)
		return;

	list->push_back(node->coord);
}



KDnode::KDnode(float val, int h)
{
	type = HYPERPLANE;
	value = val;
	coord = NULL;
	height = h;
}

KDnode::KDnode(Coordinate* coor, int h)
{
	type = POINT;
	value = 0;
	coord = coor;
	height = h;
}

void KDnode::print()
{
	if (left)
		left->print();
	//printf("Height : %d", height);
	if (type == POINT)
		printf("ID : %d, %s\n", coord->pointid, (coord->tostring()).c_str());
	/*else
		printf("Hyperplane. Value : %f\n", value);*/
	if (right)
		right->print();	
}

int find_medianPos(Coordinate** points, int start, int end, int depth)
{
	int n = end - start;
	if (n == 1)
		return start;
	depthForSort = depth;
	qsort(&points[start], n, sizeof(Coordinate*), pointcmp);

	int result = start + (n - 1) / 2;
	while (result < end - 1)
	{
		if (points[result]->val(depth) == points[result + 1]->val(depth))
			result++;
		else
			break;
	}
	return result;
}


int pointcmp(const void* a, const void* b)
{
	
	float aval = (*(Coordinate**)a)->val(depthForSort);
	float bval = (*(Coordinate**)b)->val(depthForSort);
	if (aval < bval)
		return -1;
	if (aval == bval)
		return 0;
	return 1;
}

KDnode* buildKDtree(Coordinate** points, int start, int end, int depth)
{
	if (end == start + 1)
		return new KDnode(points[start], depth);

	int medianPos = find_medianPos(points, start, end, depth);
	float median = points[medianPos]->val(depth);

	KDnode* result = new KDnode(median, depth);
	result->left = buildKDtree(points, start, medianPos + 1, depth + 1);
	result->right = buildKDtree(points, medianPos + 1, end, depth + 1);
	return result;
}