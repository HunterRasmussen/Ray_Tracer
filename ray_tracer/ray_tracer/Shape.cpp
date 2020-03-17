//
//  Shape.cpp
//  ray_tracer
//
//  Created by Hunter Rasmussen on 3/7/20.
//  Copyright © 2020 Hunter Rasmussen. All rights reserved.
//

#include "Shape.hpp"

Shape::Shape()
{
    this->shapeType = -1;
}

Shape::Shape(int shapeType_in, std::vector<Vec3> location_in, int shapeMaterial_in, Vec3 color_in, Vec3 specular_in, float phong_in)
{
    shapeType = shapeType_in;
    location = location_in;
    shapeMaterial = shapeMaterial_in;
    color = color_in;
    specular = specular_in;
    phong = phong_in;
}

