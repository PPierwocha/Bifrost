#pragma once
#include <string>
#include <vector>


class Shape
{
protected:
	std::string type;
	int physical_tag;
	std::vector<int> points_inds, neighbours;

	void assignPoints(std::vector<int> & shape_def, int ind_1, int ind_2);

public:
	Shape();
	~Shape();

};