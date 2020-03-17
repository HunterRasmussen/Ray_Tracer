//
//  Shape.hpp
//  ray_tracer
//
//  Created by Hunter Rasmussen on 3/7/20.
//  Copyright © 2020 Hunter Rasmussen. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <vector>
#include "Vec3.hpp"

class Shape
{
public:
    Shape();
    Shape(int shapeType_in, std::vector<Vec3> location_in, int shapeMaterial_in, Vec3 color_in, Vec3 specular_in, float phong_in );
    
    //for a sphere, first vec3 is center, center vec3 is the radius i.e. a radius of point two is (.2,.2,.2)
    std::vector<Vec3> location;
    //0 for circle, 1 for triangle
    int shapeType;
    //materials: 0 = diffuse, 1 = reflective;
    int shapeMaterial;
    Vec3 color;
    Vec3 specular;
    float phong;
};



#endif /* Shape_hpp */
