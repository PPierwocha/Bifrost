#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>
#include "Element.h"
#include "Line.h"
#include "Triangle.h"

struct Point {
	double x, y, z;

	Point(double x_, double y_, double z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}
};

class Mesh {

	void readGMSH(std::ifstream& mesh_file);

	void readPoints(std::ifstream& mesh_file);
	void readElements(std::ifstream& mesh_file);

public:
	std::vector<Point> nodes;
	std::vector<Element> elements;

	Mesh(std::string file_name);
	~Mesh();

	
};