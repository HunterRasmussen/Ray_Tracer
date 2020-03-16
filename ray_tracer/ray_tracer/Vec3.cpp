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

float Vec3::Dot(Vec3 b)
{
    double dot = ((b.x*this->x) + (b.y*this->y) + (b.z*this->z));
    return dot;
}


Vec3 Vec3::Add(Vec3 b)
{
    float newx = this->x + b.x;
    float newy = this->y + b.y;
    float newz = this->z + b.z;
    return Vec3(newx, newy, newz);
}

Vec3 Vec3::Subtract(Vec3 b)
{
    float newx = this->x - b.x;
    float newy = this->y - b.y;
    float newz = this->z - b.z;
    return Vec3(newx, newy, newz);
}

Vec3 Vec3::Multiply(Vec3 b)
{
    float newx = this->x * b.x;
    float newy = this->y * b.y;
    float newz = this->z * b.z;
    return Vec3(newx, newy, newz);
}

Vec3 Vec3::Scale(float b)
{
    float newx = this->x*b;
    float newy = this->y*b;
    float newz = this->z*b;
    return Vec3(newx, newy, newz);

}

Vec3 Vec3::Cross(Vec3 b)
{
    float newX = (this->y * b.z) - (this->z * b.y);
    float newY = (this->z * b.x) - (this->x * b.z);
    float newZ = (this->x * b.y) - (this->y * b.x);
    return Vec3(newX,newY,newZ);
}

float Vec3::Magnitude()
{
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

Vec3 Vec3::Normalize()
{
    float mag = this->Magnitude();
    return Vec3(this->x/mag, this->y/mag, this->z/mag);
    
}
