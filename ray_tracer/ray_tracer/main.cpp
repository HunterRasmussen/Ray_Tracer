//
//  main.cpp
//  ray_tracer
//
//  Created by Hunter Rasmussen on 3/7/20.
//  Copyright © 2020 Hunter Rasmussen. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>

#include "Ray.hpp"
#include "Vec3.hpp"
#include "Shape.hpp"


Vec3 backgroundColor = Vec3(.2,.2,.2);

std::ofstream initializeImageFile(std::string fileName, int numCol, int numRows)
{
    std::ofstream outfile;
    outfile.open(fileName);
    outfile << "P3" << std::endl;
    outfile << numCol << " " << numRows << std::endl;
    outfile << "255" << std::endl;
    return outfile;
}

//
//std::vector<Shape> initializeShapesDiffuse()
//{
//    //circle1
//}

std::vector<Shape> initializeShapesScenell()
{
    //circle1
    std::vector<Vec3> sphereLocation  = {Vec3(0,0,-.3), Vec3(.2,.2,.2)};
    Shape circle = Shape(0, sphereLocation, 1, Vec3(0,0,1), Vec3(1,1,1));
    
    std::vector<Shape> shapes = {circle};
    return shapes;
}


//Vec3 findSphereIntersection(Ray ray, std::vector<Vec3> location)
//{
//
//}

bool intersectsSphere(Ray ray, std::vector<Vec3> location)
{
    return false;
}

Vec3 calculateRay(Ray ray, std::vector<Shape> shapes)
{
    int indexofClosestIntersectingShape = -1;
    for(int i = 0; i < shapes.size(); i++)
    {
        if (shapes.at(i).shapeType == 0) //a sphere
        {
            Vec3 intersectionPoint = intersectsSphere(ray, shapes.at(i).location);
            if (intersectionPoint.x != -1000)
            {
                return shapes.at(i).color;
            }
            else
            {
                return backgroundColor;
            }
        }
        //TODO findPolygonIntersection
        else
        {
            return backgroundColor;
        }
    }
    return backgroundColor;
}

int main(int argc, const char * argv[]) {
    
    int numPixelsW = 64;
    int numPixelsH = 64;
    int totNumPixels = numPixelsH*numPixelsW;
    int fov = 28;
    Vec3 cameraPos = Vec3(0,0,1);
//    Vec3 cameraUp = Vec3(0,1,0);
    Vec3 viewDir = Vec3(0,0,0);
//    float distToScreen = 1.0f;
    Vec3 centerScreen = Vec3(0,0,0);
    float screenWidth = 2 * tan(fov/2);
    float pixelWidth = screenWidth/numPixelsW;
    float pixelHeight = screenWidth/numPixelsH;
    Vec3 screenLeft = Vec3(-1/2 * screenWidth, 0,0);
    Vec3 screenRight = Vec3(1/2*screenWidth,0,0);
    Vec3 screenTop = Vec3(1/2*screenWidth,0,0);
    Vec3 screenBot = Vec3(-1/2 * screenWidth, 0,0);

    std::string fileName = "diffuse.ppm";
    std::ofstream imageFile = initializeImageFile(fileName, numPixelsW, numPixelsH);
    std::vector<Shape> shapes = initializeShapesScenell();
    
    for (int i = 0; i < numPixelsH; i++)
    {
        float pixelCenterY = i*pixelHeight + 1/2*pixelHeight;
        for(int j = 0; j < numPixelsW; j++)
        {
            Vec3 pixelCenter = Vec3(j*pixelWidth + 1/2*pixelWidth, pixelCenterY,0);
            Ray ray = Ray(cameraPos, pixelCenter);
            Vec3 outColor = calculateRay(ray, shapes);
        }
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
