#include "Coordinate.h"


Coordinate::Coordinate(float*inputs, int id, int dim)
{
	pointid = id;
	k = dim;
	values = (float*)malloc(k*sizeof(float));
	memcpy(values, inputs, k*sizeof(float));
	iscore = false;
	ismember = false;
}

Coordinate::~Coordinate()
{
	free(values);
}

float Coordinate::val(int dimen)
{
	return values[dimen%k];
}


string Coordinate::tostring()
{
	string result = "(";
	for (int i = 0; i < k; i++)
	{
		result.append(std::to_string(values[i]));
		if (i == k - 1)
			result += ")";
		else
			result += ", ";
	}
	return result;
}

bool Coordinate::comp(const Coordinate* t1, const Coordinate* t2)
{
	return t1->pointid < t2->pointid;
}

CoordinateSet::CoordinateSet(vector<Coordinate*> *pts)
{
	points = pts;
	num = pts->size();
}

void CoordinateSet::print()
{
	sort(points->begin(), points->end(), Coordinate::comp);
	Coordinate *probe = points[0];
	for (int i = 0; i < points->size(); i++)
	{
		
	}
}