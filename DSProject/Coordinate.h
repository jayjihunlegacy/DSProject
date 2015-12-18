#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Coordinate
{
public:
	Coordinate(float*inputs, int id, int k);
	~Coordinate();
	string tostring();
	float val(int);

	int pointid;
	float *values;
	int k;
	bool iscore;
	bool ismember;

	static bool comp(const Coordinate* t1, const Coordinate* t2);
};

class CoordinateSet
{
public:
	CoordinateSet(vector<Coordinate*> *);

	Coordinate**points;
	//vector<Coordinate*>* points;
	int num;
	void print();
};