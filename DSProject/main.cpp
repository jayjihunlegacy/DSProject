#include "kdtree.h"
#include "DBSCAN.h"
int main()
{
	int k = 3;
	int n = 10;
	float** points = (float**)malloc(n*sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		points[i] = (float*)malloc(k*sizeof(float));
		points[i][0] = points[i][1]=points[i][2]=i;
	}

	KDtree * kdtree = new KDtree(points, k, n);
	//kdtree->print();
	DBSCAN* scanner = new DBSCAN(kdtree, 0.01, 2);
	scanner->run();
}