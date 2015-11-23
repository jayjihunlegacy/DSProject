#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

template <int k>
class Coordinate
{
public:
	Coordinate(float*inputs, int id);
	~Coordinate();
	string tostring();
	float val(int);

	int pointid;
	float *values;
};

template <int k>
class CoordinateSet
{
public:
	CoordinateSet();
	insert(Coordinate*);

	void print();
}