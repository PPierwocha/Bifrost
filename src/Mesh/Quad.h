#pragma once
#include "Shape.h"
class Quad :
    public Shape
{
public:
    Quad(std::vector<int>& gmsh_definition);
    ~Quad();
};

