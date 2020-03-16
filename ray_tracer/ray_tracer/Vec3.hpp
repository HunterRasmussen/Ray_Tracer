//
//  Vec3.hpp
//  ray_tracer
//
//  Created by HunterRasmussen on 3/7/20.
//  Copyright © 2020 Hunter Rasmussen. All rights reserved.
//

#ifndef Vec3_hpp
#define Vec3_hpp

#include <math.h>


class Vec3
{
public:
    Vec3();
    Vec3(float x_in, float y_in, float z_in);
    
    
    Vec3 Add(Vec3 b);
//
//    void Subtract(Vec3 b);
//
//    void ScalarMultiplication(float s);
//
    float Magnitude();
    Vec3 Normalize();
    float Dot(Vec3 b);
    Vec3  Subtract(Vec3 b);
    Vec3 Scale(float b);
    Vec3 Multiply(Vec3 b);
    Vec3 Cross(Vec3 b);
//
//    void Lerp(Vec3 b, float t);
//
//    void RotateZ(float angle);
//
    float x;
    float y;
    float z;
};
#endif /* Vec3_hpp */
