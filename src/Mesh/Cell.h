#pragma once
#include "Shape.h"
#include "Line.h"
#include "Triangle.h"
#include "Quad.h"


class Cell
{
	Shape cell_shape;

public:
	Cell(Shape & shape_);
	~Cell();
};

