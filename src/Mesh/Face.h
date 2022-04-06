#pragma once
#include "Shape.h"
#include "Line.h"
#include "Triangle.h"
#include "Quad.h"

class Face
{
	Shape face_shape;

public:
	int neighbour;
	std::vector<double> normal_vector;
	double area;


	Face();
	~Face();
};

