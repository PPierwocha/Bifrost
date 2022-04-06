#pragma once
#include "Shape.h"
class Line : public Shape
{

public:
	Line(std::vector<int>& gmsh_definition);
	~Line();
};

