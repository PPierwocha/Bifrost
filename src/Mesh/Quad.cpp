#include "Quad.h"


Quad::Quad(std::vector<int>& gmsh_definition)
{
	type = "Quad";
	physical_tag = gmsh_definition[3];
	assignPoints(gmsh_definition, 5, 8);
}

Quad::~Quad()
{

}