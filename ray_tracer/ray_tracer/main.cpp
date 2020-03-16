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


# define M_PI           3.14159265358979323846  /* pi */

Vec3 backgroundColor = Vec3(0.2f,0.2f,0.2f);
Vec3 ambientColor = Vec3(0,0,0);
Vec3 directionToLight = Vec3(0,1,0);
Vec3 lightColor = Vec3(1,1,1);


std::ofstream initializeImageFile(std::string fileName, int numCol, int numRows)
{
    std::ofstream outfile;
    outfile.open(fileName);
    outfile << "P3" << std::endl;
    outfile << numCol << " " << numRows << std::endl;
    outfile << "255" << std::endl;
//    for (int i = 0; i < numRows; i++)
//    {
//        for(int j = 0; j < numCol; j++)
//        {
//            float r = float(j) / float(numCol);
//            float g = float(i)/ float(numRows);
//            float b = 0.2f;
//            int ir = int(255.99*r);
//            int ig = int(255.99*g);
//            int ib = int(255.99*b);
//            outfile << ir << " " << ig << " " << ib << std::endl;
//        }
//    }
    return outfile;
}

//
//std::vector<Shape> initializeShapesDiffuse()
//{
//    //circle1
//}
//
std::vector<Shape> initializeShapesScenell()
{
    //circle1
    std::vector<Vec3> sphereLocation  = {Vec3(0,0.3,0), Vec3(.2,.2,.2)};
    Shape circle = Shape(0, sphereLocation, 1, Vec3(0,0,1), Vec3(1,1,1));
    //triangle 1
//    Triangle 0 -.5 .5   1 .5 0   0 -.5 -.5    Material Diffuse 0 0 1 SpecularHighlight 1 1 1 PhongConstant 4
    std::vector<Vec3> triangleVerts = {Vec3(0,-0.5,0.5), Vec3(1,0.5,0) , Vec3(0,-0.5,-0.5)};
    Shape tri1 = Shape(1, triangleVerts, 1, Vec3(0,0,1), Vec3(1,1,1));
    std::vector<Shape> shapes = {circle, tri1};
    return shapes;
}


//Vec3 findSphereIntersection(Ray ray, std::vector<Vec3> location)
//{
//
//}


bool isInsidePoly(std::vector<std::vector<float>> vertices)
{
    int signHolder = 0;
    int nextSignHolder = 0;
    int numCrossings = 0;
    float intersectionPoint = 0;
    
    if(vertices.at(0).at(1) < 0)
    {
        signHolder = -1;
    }
    else
    {
        signHolder = 1;
    }
    for(int i = 0; i < vertices.size(); i++)
    {
        if i == vertices.size() -1
    }
    
}

//returns -1.0 if it doesn't intersect polygon
// otherwise returns t, the parameter value for solving the intersection
float intersectsPolygon(Ray ray, std::vector<Vec3> vertices)
{
    
    Vec3 edge1 = vertices.at(0).Subtract(vertices.at(1));
    Vec3 edge2 = vertices.at(1).Subtract(vertices.at(2));
    Vec3 normal = edge1.Cross(edge2);
    normal = normal.Normalize();
    float D = normal.Dot(vertices.at(0));
    float vd =  normal.Dot(ray.direction);//normal dot ray origin
    if(vd > 0) //normal is facing away from camera.  Culled
    {
        return -1.0;
    }
    else if(vd == 0) //ray is // to plane
    {
        return -1.0;
    }
    
    float vo = normal.Dot(ray.origin) + D;
    float t = vo/vd;
    if (t < 0) //intersection is behind ray origin
    {
        return -1.0;
    }
    
    Vec3 intersectionPoint = ray.origin.Add(ray.direction.Scale(t));
    std::vector<float> projectedIntersectionPoint = {};
    std::vector<std::vector<float>> projectedPolygonVertices = {};

    if (abs(normal.x) >= abs(normal.y) && abs(normal.x) >= abs(normal.z)) //normal.x has largest mag
    {
        projectedIntersectionPoint.push_back(intersectionPoint.y);
        projectedIntersectionPoint.push_back(intersectionPoint.z);
        for(int i = 0; i < vertices.size(); i++)
        {
            Vec3 curVertex = vertices.at(i);
            std::vector<float> vertex = {curVertex.y, curVertex.z};
            projectedPolygonVertices.push_back(vertex);
        }
    }
    else if(abs(normal.y) >= abs(normal.x) && abs(normal.y) >= (normal.z)) //normal.y has largest mag
    {
        projectedIntersectionPoint.push_back(intersectionPoint.x);
        projectedIntersectionPoint.push_back(intersectionPoint.z);
        for(int i = 0; i < vertices.size(); i++)
        {
            Vec3 curVertex = vertices.at(i);
            std::vector<float> vertex = {curVertex.x, curVertex.z};
            projectedPolygonVertices.push_back(vertex);
        }
    }
    else //normal.z has largest mag
    {
        projectedIntersectionPoint.push_back(intersectionPoint.x);
        projectedIntersectionPoint.push_back(intersectionPoint.y);
        for(int i = 0; i < vertices.size(); i++)
        {
            Vec3 curVertex = vertices.at(i);
            std::vector<float> vertex = {curVertex.x, curVertex.y};
            projectedPolygonVertices.push_back(vertex);
        }
    }
    
    for(int i = 0; i < projectedPolygonVertices.size(); i++) //translate all vertices
    {
        std::vector<float> curVertex = projectedPolygonVertices.at(i);
        curVertex.at(0) = curVertex.at(0)- projectedIntersectionPoint.at(0);
        curVertex.at(1) = curVertex.at(1)- projectedIntersectionPoint.at(1);
    }
    
    bool isInside = isInsidePoly(projectedPolygonVertices);
    
    

    
//    return t;
}

//returns -1.0 if it doesn't intersect sphere
float intersectsSphere(Ray ray, std::vector<Vec3> location)
{
    Vec3 oc = ray.origin.Subtract(location.at(0));
    float A = ray.direction.Dot(ray.direction);
    float B = 2* ray.direction.Dot(oc);
    float R = location.at(1).x;
    float C = oc.Dot(oc) - R;
    float discriminant = B*B - 4*A*C;
//    std::cout << "Discriminant = " << discriminant << std::endl;
//    if(ray.direction.x == 0 && ray.direction.y == 0)
//    {
//        std::cout << std::endl << std::endl << "Center Pixel" << std::endl;
//        std::cout << "A = "  << A << " B = " << B << " C = " << C << std::endl;
//        std::cout << "R = " << R << std::endl;
//        std::cout << "Origin =  " << ray.origin.x << ", "  << ray.origin.y << ", " << ray.origin.z << std::endl;
//        std::cout << "Direction =  " << ray.direction.x << ", "  << ray.direction.y << ", " << ray.direction.z << std::endl;
//        std::cout << "Center =  " << location.at(0).x << ", "  << location.at(0).y << ", " << location.at(0).z << std::endl;
//        std::cout << "Discriminant = " << discriminant << std::endl;
//    }
    if(discriminant < 0)
    {
        return -1.0;
    }
    
    float closest = (-B - sqrt(discriminant)) / 2*A;
    if( closest > 0)
    {
        return closest;
    }
    else
    {
        return ((-B + sqrt(discriminant))/ 2*A);
    }
}

Vec3 calculateRay(Ray ray, std::vector<Shape> shapes)
{
    float t_intsersect = intersectsSphere(ray, shapes.at(0).location);
    if (t_intsersect > 0)
    {
        Vec3 intersectionPoint = ray.origin.Add(ray.direction.Scale(t_intsersect));
        Vec3 normal = shapes.at(0).location.at(0).Add(intersectionPoint).Normalize();
        Vec3 ambient = shapes.at(0).color.Multiply(ambientColor);
        Vec3 diffuse = shapes.at(0).color.Multiply(lightColor);
        float ndotL = normal.Dot(directionToLight);
        diffuse = diffuse.Scale(ndotL);
        return diffuse.Add(ambient);
//        std::cout << "Normal = " << normal.x << " " << normal.y << " " << normal.z << std::endl;
//        Vec3 toReturn = Vec3(normal.x + 1, normal.y + 1, normal.z + 1).Scale(0.5f);
//        std::cout << "To return = " << toReturn.x << " " << toReturn.y << " " << toReturn.z << std::endl;
        
//        return toReturn;
    }
    
    t_intsersect = intersectsPolygon(ray, shapes.at(0).location);
    
    return backgroundColor;
//    int indexofClosestIntersectingShape = -1;
//    for(int i = 0; i < shapes.size(); i++)
//    {
//        if (shapes.at(i).shapeType == 0) //a sphere
//        {
//            Vec3 intersectionPoint = intersectsSphere(ray, shapes.at(i).location);
//            if (intersectionPoint.x != -1000)
//            {
//                return shapes.at(i).color;
//            }
//            else
//            {
//                return backgroundColor;
//            }
//        }
//        //TODO findPolygonIntersection
//        else
//        {
//            return backgroundColor;
//        }
//    }
//    return backgroundColor;
}

int main(int argc, const char * argv[]) {
    
    int numPixelsW = 256;
    int numPixelsH = 256;
//    int totNumPixels = numPixelsH*numPixelsW;
    int fov = 55;
    Vec3 cameraPos = Vec3(0,0,1.2);  //look from
//    Vec3 cameraUp = Vec3(0,1,0);
    float distToScreen = 1.2f;
//    Vec3 lookat = Vec3(0,0,0);
    float screenWidth = 2* tan(fov * M_PI/180) * distToScreen;
    float pixelWidth = screenWidth/numPixelsW;
    //assuming square image plane
    float pixelHeight = screenWidth/numPixelsH;
    float screenleftx =  -screenWidth/2;
    float screenTopy = screenWidth/2;
    Vec3 screenLeft = Vec3(screenleftx , 0,0);
//    Vec3 screenRight = Vec3(1/2 *screenWidth,0,0);
    Vec3 screenTop = Vec3(0,screenTopy,0);
//    Vec3 screenBot = Vec3(0, -1/2 * screenWidth,0);
    std::cout <<"screenLeft = " << screenLeft.x << " screen top = " << screenTop.y << std::endl;
    std::string fileName = "diffuse.ppm";
    std::ofstream imageFile = initializeImageFile(fileName, numPixelsW, numPixelsH);
    imageFile.flush();
    std::vector<Shape> shapes = initializeShapesScenell();
    
    for (int i = 0; i < numPixelsH; i++)
    {
        float pixelCenterY = screenTop.y - (i*pixelHeight) - (1/2 *pixelHeight);
        for(int j = 0; j < numPixelsW; j++)
        {
            float pixelCenterX = screenLeft.x + (j*pixelWidth) + (1/2*pixelWidth);
            Vec3 pixelCenter = Vec3(pixelCenterX, pixelCenterY,0);
//            std::cout << "X : " << pixelCenterX << " Y : " << pixelCenterY << std::endl;
            Ray ray = Ray(cameraPos, pixelCenter.Subtract(cameraPos));
            Vec3 outColor = calculateRay(ray, shapes).Scale(255);
//            std::cout << outColor.x << " " << outColor.y << " " << outColor.z << std::endl;
            imageFile << floor(outColor.x) << " " << floor(outColor.y) << " " << floor(outColor.z) << std::endl;
        }
    }
    imageFile.flush();
    std::cout << "Hello, World!\n";
    return 0;
}
