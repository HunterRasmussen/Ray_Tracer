//
//  Vec3.cpp
//  ray_tracer
//
//  Created by Hunter Rasmussen on 3/7/20.
//  Copyright © 2020 Hunter Rasmussen. All rights reserved.
//

#include "Vec3.hpp"

Vec3::Vec3()
{
    x = -100;
    y = -100;
    z = -100;
}

Vec3::Vec3(float x_in, float y_in, float z_in)
{
    x = x_in;
    y = y_in;
    z = z_in;
}
