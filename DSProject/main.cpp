#include "kdtree.h"
#include "DBSCAN.h"
int main()
{
	int k = 2;
	int n = 11;
	float epsilon = 2;
	int minNeighbor = 2;


	float pts[11][2] = {
		{0,5},
		{1,6},
		{2,7},
		{2,4},
		{2,2},
		{3,2},
		{4,9},
		{4,1},
		{5,3},
		{6,4},
		{7,1}
	};
	
	float** points = (float**)malloc(n*sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		points[i] = (float*)malloc(k*sizeof(float));
		for (int j = 0; j < k; j++)
			points[i][j] = pts[i][j];
	}

	KDtree * kdtree = new KDtree(points, k, n);
	DBSCAN* scanner = new DBSCAN(kdtree, epsilon, minNeighbor);
	scanner->run();
}