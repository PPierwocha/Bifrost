#include "Shape.h"



void Shape::assignPoints(std::vector<int> & shape_def, int ind_1, int ind_2)
{
	for (int i = ind_1; i <= ind_2; i++)
		points_inds.push_back(shape_def[i]);
}

Shape::Shape()
{

}


Shape::~Shape()
{

}