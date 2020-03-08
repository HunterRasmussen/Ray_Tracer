//
//  Ray.hpp
//  ray_tracer
//
//  Created by Hunter Rasmussen on 3/7/20.
//  Copyright © 2020 Hunter Rasmussen. All rights reserved.
//

#ifndef Ray_hpp
#define Ray_hpp

#include <stdio.h>

#include "Vec3.hpp"

class Ray
{
public:
    Ray(Vec3 origin_in, Vec3 direction_in);
//    Ray();
    Vec3 origin;
    Vec3 direction;
};

#endif /* Ray_hpp */
