#include "Line.h"


Line::Line(std::vector<int>& gmsh_definition)
{
	type = "Line";
	physical_tag = gmsh_definition[3];
	assignPoints(gmsh_definition, 5, 6);
}


Line::~Line()
{

}