#include "kdtree.h"
#include "DBSCAN.h"
#include <crtdbg.h>
#include <fstream>
#include <iostream>
float ** datainput(int n, int k)
{
	float ** result = (float**)malloc(sizeof(float*)*n);
	ifstream fin;
	fin.open("C://data.txt");
	
	for (int i = 0; i < n; i++)
	{
		result[i] = (float*)malloc(sizeof(float)*k);
		int n;
		float a, b;
		fin >> n;
		fin >> a;
		fin >> b;
		result[i][0] = a;
		result[i][1] = b;
	}
	return result;
}

void test1()
{
	int k = 2;
	int n = 11;
	float epsilon = 2;
	int minNeighbor = 2;


	float pts[11][2] = {
		{ 0,5 },
		{ 1,6 },
		{ 2,7 },
		{ 2,4 },
		{ 2,2 },
		{ 3,2 },
		{ 4,9 },
		{ 4,1 },
		{ 5,3 },
		{ 6,4 },
		{ 7,1 }
	};

	float** points = (float**)malloc(n*sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		points[i] = (float*)malloc(k*sizeof(float));
		for (int j = 0; j < k; j++)
			points[i][j] = pts[i][j];
	}

	KDtree * kdtree = new KDtree(points, k, n);
	for (int i = 0; i < n; i++)
		free(points[i]);
	free(points);
	DBSCAN* scanner = new DBSCAN(kdtree, epsilon, minNeighbor);
	scanner->run();
	delete kdtree;
	delete scanner;
}

void test2()
{
	int k = 2;
	int n = 37;
	float epsilon = 1;
	int minNeighbor = 2;

	float pts[37][2] = {
		{5,4},
		{4,5},
		{4,4},
		{4,3},
		{4,-1},
		{4,-2},
		{4,-3},
		{3,4},
		{3,1},
		{3,-3},
		{2,2},
		{2,1},
		{2,0},
		{2,-1},
		{2,-3},
		{0,4},
		{0,3},
		{0,2},
		{0,1},
		{ -2,  1},
		{ -2,  0},
		{ -2, -1},
		{ -2, -3},
		{ -2, -4},
		{ -2, -5},
		{ -3,  1 },
		{ -3,  0 },
		{ -3, -1 },
		{ -3, -3 },
		{ -3, -4 },
		{ -3, -5 },
		{ -4,  1 },
		{ -4,  0 },
		{ -4, -1 },
		{ -4, -3 },
		{ -4, -4 },
		{ -4, -5 }
	};

	float** points = (float**)malloc(n*sizeof(float*));
	for (int i = 0; i < n; i++)
	{
		points[i] = (float*)malloc(k*sizeof(float));
		for (int j = 0; j < k; j++)
			points[i][j] = pts[i][j];
	}

	KDtree * kdtree = new KDtree(points, k, n);
	for (int i = 0; i < n; i++)
		free(points[i]);
	free(points);
	DBSCAN* scanner = new DBSCAN(kdtree, epsilon, minNeighbor);
	scanner->run();
	delete kdtree;
	delete scanner;
}

void test3()
{
	int k = 2;
	int n = 244;
	float epsilon = 1;
	int minNeighbor = 2;

	float **points = datainput(n, k);

	KDtree * kdtree = new KDtree(points, k, n);
	for (int i = 0; i < n; i++)
		free(points[i]);
	free(points);
	DBSCAN* scanner = new DBSCAN(kdtree, epsilon, minNeighbor);
	scanner->run();
	delete kdtree;
	delete scanner;
}

int main()
{
	//_CrtSetBreakAlloc(157);
	//test1();
	test2();
	_CrtDumpMemoryLeaks();
}