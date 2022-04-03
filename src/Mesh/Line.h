#pragma once
#include "Element.h"
class Line : public Element
{

public:
	Line(std::vector<int>& gmsh_definition);
	~Line();
};

