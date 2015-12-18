#include "DBSCAN.h"

DBSCAN::DBSCAN(KDtree*kdtree, float epsilon, int minNeighbor)
{
	this->kdtree = kdtree;
	ep = epsilon;
	minNei = minNeighbor;
	num = kdtree->num;
	set = (DSnode**)malloc(num*sizeof(DSnode*));
}

DBSCAN::~DBSCAN()
{
	for (int i = 0; i < num; i++)
		delete set[i];
	free(set);
}

void DBSCAN::run()
{
	//for each, make!
	setmake(0,kdtree->root);
	sort(set, &set[num], DSnode::comp);
	//for each, run!
	setrun(kdtree->root);

	for (int i = 0; i < num; i++)
	{
		int point_id = set[i]->coord->pointid + 1;
		int c_id = DSnode::FIND(set[i])->coord->pointid;
		c_id = set[i]->coord->ismember ? c_id + 1: -1;
		printf("%d %d\n",point_id,c_id);
	}
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
	//printf("Set run Called for value : %2.2f\n", node->value);
	if (!node)
		return;
	if (node->type == HYPERPLANE)
	{
		setrun(node->left);
		setrun(node->right);
		return;
	}
	else
	{
		CoordinateSet * cs = kdtree->getNeighbors(node, ep);
		//cs->print();
		if (cs->num < 2)
		{
			delete cs;
			return;
		}
		node->coord->iscore = true;
		for (int i = 0; i < cs->num; i++)
		{
			Coordinate* probe = cs->points[i];
			if (probe->iscore)
			{
				node->coord->ismember = true;
				DSnode::UNION(set[node->coord->pointid], set[probe->pointid]);
			}
			else if(!(probe->ismember))
			{
				probe->ismember = true;
				node->coord->ismember = true;
				DSnode::UNION(set[node->coord->pointid], set[probe->pointid]);
			}
		}
		delete cs;
	}
}