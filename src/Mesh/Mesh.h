#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>
#include "Cell.h"

struct Point {
	double x, y, z;

	Point(double x_, double y_, double z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}
};

struct PhysicalEntity {
	int physical_tag;
	std::string physical_name;

	PhysicalEntity(int physical_tag_, std::string physical_name_)
	{
		physical_tag = physical_tag_;
		physical_name = physical_name_;
	}
};

class Mesh {
private:


protected:
	int mesh_dim;

	void readGMSH(std::ifstream& mesh_file);

	void readPhysicalEntities(std::ifstream& mesh_file);
	void readPoints(std::ifstream& mesh_file);
	void readElements(std::ifstream& mesh_file);

	void initFaces();
public:
	std::vector<Point> nodes;
	std::vector<PhysicalEntity> physical_entities;
	std::vector<Cell> internal_elements;
	std::vector<Shape> boundary_elements;
	//std::vector<Element> faces;

	Mesh(std::string file_name);
	~Mesh();

	
};