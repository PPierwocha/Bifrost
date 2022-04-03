#include "Triangle.h"

Triangle::Triangle(std::vector<int>& gmsh_definition)
{
	type = "Triangle";
	physical_tag = gmsh_definition[3];
	assignPoints(gmsh_definition, 5, 7);
}

Triangle::~Triangle()
{
}
