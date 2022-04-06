#pragma once
#include "Shape.h"
class Triangle : public Shape
{

public:
	Triangle(std::vector<int>& gmsh_definition);
	~Triangle();
};

