#pragma once
#include "Element.h"
class Triangle : public Element
{

public:
	Triangle(std::vector<int>& gmsh_definition);
	~Triangle();
};

