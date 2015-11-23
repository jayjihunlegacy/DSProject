#include "Coordinate.h"

template <int k>
Coordinate<k>::Coordinate(float*inputs, int id)
{
	pointid = id;
	values = (float*)malloc(k*sizeof(float));
	memcpy(values, (const void*)inputs, k*sizeof(float));
}

template <int k>
Coordinate<k>::~Coordinate()
{
	free(values);
}

template <int k>
int Coordinate<k>::val(int dimen)
{
	return dimen < k ? values[dimen] : 0;
}


template <int k>
string Coordinate<k>::tostring()
{
	string result = "(";
	for (int i = 0; i < k; i++)
	{
		result += values[i];
		if (i == k - 1)
			result += ")";
		else
			result += ", ";
	}
	return result;
}