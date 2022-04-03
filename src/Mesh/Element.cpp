#include "Element.h"



void Element::assignPoints(std::vector<int> & element_def, int ind_1, int ind_2)
{
	for (int i = ind_1; i <= ind_2; i++)
		points_inds.push_back(element_def[i]);
}

Element::Element()
{

}


Element::~Element()
{

}