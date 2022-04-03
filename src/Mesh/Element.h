#pragma once
#include <string>
#include <vector>


class Element
{
protected:
	std::string type;
	int physical_tag;
	std::vector<int> points_inds;

	void assignPoints(std::vector<int> & element_def, int ind_1, int ind_2);

public:
	Element();
	~Element();

};