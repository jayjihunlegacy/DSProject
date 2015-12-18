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
	//printf("Coordinate dtr called for point id %d\n", pointid);
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
	num = pts->size();
	if (num == 0)
		points = NULL;
	else
	{
		sort(pts->begin(), pts->end(), Coordinate::comp);
		points = (Coordinate**)malloc(sizeof(Coordinate*)*num);
		memcpy(points, &(pts->front()), sizeof(Coordinate*)*num);
	}	
}

CoordinateSet::~CoordinateSet()
{
	//printf("CoordinateSet dtr Called\n");
	free(points);
}

void CoordinateSet::print()
{
	if (num == 0)
		return;
	for (int i = 0; i < num; i++)
	{
		Coordinate* probe = points[i];
		printf("%s\n", probe->tostring().c_str());
	}
}