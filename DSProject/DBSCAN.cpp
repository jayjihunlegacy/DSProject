#include "DBSCAN.h"

DBSCAN::DBSCAN(KDtree*kdtree, float epsilon, int minNeighbor)
{
	this->kdtree = kdtree;
	ep = epsilon;
	minNei = minNeighbor;
	num = kdtree->num;
	set = (DSnode**)malloc(num*sizeof(DSnode*));
}

void DBSCAN::run()
{
	printf("HELLO WORLD!\n");
	setmake(0,kdtree->root);
	setrun(kdtree->root);
}

int DBSCAN::setmake(int seq, KDnode* node)
{
	if (!node)
		return seq;

	if (node->type == HYPERPLANE)
	{
		int newseq = setmake(seq, node->left);
		return setmake(newseq, node->right);
	}

	set[seq] = new DSnode(node->coord);
	return seq + 1;
}

void DBSCAN::setrun(KDnode* node)
{
	if (!node)
		return;
	if (node->type == HYPERPLANE)
	{
		setrun(node->left);
		setrun(node->right);
	}
	CoordinateSet * cs = kdtree->getNeighbors(node, ep);
	if (cs->num < 2)
		return;
	node->coord->iscore = true;
	//for each nodes in cs,
	//blah~~
}