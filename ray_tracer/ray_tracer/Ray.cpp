//
//  Ray.cpp
//  ray_tracer
//
//  Created by Hunter Rasmussen on 3/7/20.
//  Copyright © 2020 Hunter Rasmussen. All rights reserved.
//

#include "Ray.hpp"
//#include "Vec3.hpp"


Ray::Ray(Vec3 origin_in, Vec3 direction_in):origin(origin_in),direction(direction_in)
{
    origin = origin_in;
    direction = direction_in;
}
