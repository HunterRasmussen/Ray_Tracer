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
#include <cmath>
#include <string.h>
#include <vector>

#include "Ray.hpp"
#include "Vec3.hpp"
#include "Shape.hpp"


# define M_PI           3.14159265358979323846  /* pi */

Vec3 backgroundColor = Vec3(0.2f,0.2f,0.2f);
Vec3 ambientColor = Vec3(0.1,0.1,0.1);
Vec3 directionToLight = Vec3(1,0,0);
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


std::vector<Shape> initializeShapesCustom()
{
    
    //circle1
    //    BackgroundColor .2 .2 .2
    //    Sphere Center .35 0 -.1 Radius .05 Material Diffuse 1 1 1 SpecularHighlight 1 1 1 PhongConstant 4
    std::vector<Vec3> sphereLocation1  = {Vec3(0.35,.6,-.1), Vec3(.01,.01,.01)};
    Shape circle1 = Shape(0, sphereLocation1, 0, Vec3(1,1,1), Vec3(1,1,1), 4);
    //    Sphere Center .2 0 -.1 Radius .075 Material Diffuse 1 0 0 SpecularHighlight .5 1 .5 PhongConstant 32
    std::vector<Vec3> sphereLocation2  = {Vec3(0.2,-.1,-.1), Vec3(.07,.07,.07)};
    Shape circle2 = Shape(0, sphereLocation2, 0, Vec3(1,0,0), Vec3(.5,1,.5), 32);
    
    //    Sphere Center -.6 0 0 Radius .3 Material Diffuse 0 1 0 SpecularHighlight .5 1 .5 PhongConstant 32
    std::vector<Vec3> sphereLocation3  = {Vec3(-0.6,.4,0), Vec3(.05,.05,05)};
    Shape circle3 = Shape(0, sphereLocation3, 0, Vec3(0,1,0), Vec3(.5,1,.5), 32);
    
    
    //    Sphere Center -.6 0 0 Radius .3 Material Diffuse 0 1 0 SpecularHighlight .5 1 .5 PhongConstant 32
    std::vector<Vec3> sphereLocation4  = {Vec3(-0.1,.5,0), Vec3(.02,.05,05)};
    Shape circle4 = Shape(0, sphereLocation4, 1, Vec3(0,1,0), Vec3(.5,1,.5), 32);
    
    std::vector<Vec3> sphereLocation5  = {Vec3(-0.1,0,-.8), Vec3(.2,.2, .2)};
    Shape circle5 = Shape(0, sphereLocation5, 0, Vec3(0,0,1), Vec3(.5,1,.5), 32);
    
    std::vector<Vec3> sphereLocation6  = {Vec3(-0.3,-0.3,.3), Vec3(.01,.01, .01)};
    Shape circle6 = Shape(0, sphereLocation6, 1, Vec3(0,0,1), Vec3(.5,1,.5), 32);
    
    std::vector<Vec3> sphereLocation7  = {Vec3(0.4,.3,-.4), Vec3(.03,.03,.03)};
    Shape circle7 = Shape(0, sphereLocation7, 0, Vec3(1,0,0), Vec3(1,1,0), 4);
    
    std::vector<Vec3> sphereLocation8  = {Vec3(0.0,-0.2,.3), Vec3(.01,.01,.01)};
    Shape circle8 = Shape(0, sphereLocation8, 0, Vec3(.3,.3,.9), Vec3(1,0,0), 16);
    
    std::vector<Vec3> sphereLocation9  = {Vec3(0.35,-0.2,.2), Vec3(.001,.001,.001)};
    Shape circle9 = Shape(0, sphereLocation9, 1, Vec3(.3,.3,.9), Vec3(1,0,0), 16);
    
    
    //    Triangle .3 -.3 -.4  0 .3 -.1  -.3 -.3 .2 Material Diffuse 0 0 1 SpecularHighlight 1 1 1 PhongConstant 32
    std::vector<Vec3> triangleVerts = {Vec3(-.4,0,-1), Vec3(4,0,-1) , Vec3(0,0,10)};
    Shape tri1 = Shape(1, triangleVerts, 0, Vec3(0,0,1), Vec3(1,1,1), 32);
    //    Triangle  -.2 .1 .1   -.2 -.5 .2   -.2 .1 -.3 Material Diffuse 1 1 0 SpecularHighlight 1 1 1 PhongConstant 4
//    std::vector<Vec3> triangle2Verts = {Vec3(-.2,.1,.1), Vec3(-0.2,-0.5,0.2) , Vec3(-0.2,0.1,-0.3)};
//    Shape tri2 = Shape(1, triangle2Verts, 0, Vec3(1,1,0), Vec3(1,1,1), 4);
    std::vector<Shape> shapes = {circle1, circle2, circle3, circle4, circle5, circle6, circle7, circle8, circle9};
    return shapes;
}

//
std::vector<Shape> initializeShapesDiffuse()
{
    //circle1
//    BackgroundColor .2 .2 .2
//    Sphere Center .35 0 -.1 Radius .05 Material Diffuse 1 1 1 SpecularHighlight 1 1 1 PhongConstant 4
    std::vector<Vec3> sphereLocation1  = {Vec3(0.35,0,-.1), Vec3(.001,.001,.001)};
    Shape circle1 = Shape(0, sphereLocation1, 0, Vec3(1,1,1), Vec3(1,1,1), 4);
//    Sphere Center .2 0 -.1 Radius .075 Material Diffuse 1 0 0 SpecularHighlight .5 1 .5 PhongConstant 32
    std::vector<Vec3> sphereLocation2  = {Vec3(0.2,0,-.1), Vec3(.007,.007,.007)};
    Shape circle2 = Shape(0, sphereLocation2, 0, Vec3(1,0,0), Vec3(.5,1,.5), 32);

//    Sphere Center -.6 0 0 Radius .3 Material Diffuse 0 1 0 SpecularHighlight .5 1 .5 PhongConstant 32
    std::vector<Vec3> sphereLocation3  = {Vec3(-0.6,0,0), Vec3(.1,.1,1)};
    Shape circle3 = Shape(0, sphereLocation3, 0, Vec3(0,1,0), Vec3(.5,1,.5), 32);
    
    
//    Triangle .3 -.3 -.4  0 .3 -.1  -.3 -.3 .2 Material Diffuse 0 0 1 SpecularHighlight 1 1 1 PhongConstant 32
    std::vector<Vec3> triangleVerts = {Vec3(.3,-0.3,-0.4), Vec3(0,0.3,-0.1) , Vec3(-0.3,-0.3,0.2)};
    Shape tri1 = Shape(1, triangleVerts, 0, Vec3(0,0,1), Vec3(1,1,1), 32);
//    Triangle  -.2 .1 .1   -.2 -.5 .2   -.2 .1 -.3 Material Diffuse 1 1 0 SpecularHighlight 1 1 1 PhongConstant 4
    std::vector<Vec3> triangle2Verts = {Vec3(-.2,.1,.1), Vec3(-0.2,-0.5,0.2) , Vec3(-0.2,0.1,-0.3)};
    Shape tri2 = Shape(1, triangle2Verts, 0, Vec3(1,1,0), Vec3(1,1,1), 4);
    std::vector<Shape> shapes = {circle1, circle2, circle3, tri1, tri2};
    return shapes;
}
//
std::vector<Shape> initializeShapesScenell()
{
    //circle1
    std::vector<Vec3> sphereLocation  = {Vec3(0,0.3,0), Vec3(.02,.02,.02)};
    Shape circle = Shape(0, sphereLocation, 1, Vec3(0,0,1), Vec3(1,1,1), 4);
    //triangle 1
//    Triangle 0 -.5 .5   1 .5 0   0 -.5 -.5    Material Diffuse 0 0 1 SpecularHighlight 1 1 1 PhongConstant 4
    std::vector<Vec3> triangleVerts = {Vec3(0,-0.5,0.5), Vec3(1,0.5,0) , Vec3(0,-0.5,-0.5)};
    Shape tri1 = Shape(1, triangleVerts, 0, Vec3(0,0,1), Vec3(1,1,1), 4);

    std::vector<Vec3> triangle2Verts = {Vec3(0,-0.5,-0.5), Vec3(0,-0.5,0.5) , Vec3(-1,0.5,0)};
    Shape tri2 = Shape(1, triangle2Verts, 0, Vec3(1,1,0), Vec3(1,1,1), 4);

    std::vector<Shape> shapes = {circle, tri1, tri2};
    return shapes;
}



Vec3 computeNormal(std::vector<Vec3> vertices)
{
    Vec3 edge1 = vertices.at(0).Subtract(vertices.at(1));
    Vec3 edge2 = vertices.at(1).Subtract(vertices.at(2));
    Vec3 normal = edge1.Cross(edge2);
    normal = normal.Normalize();
    return normal;
}

//bool isInsideTriangle(std::vector<std::vector<float>> vertices)
//{
//    
//}

//returns normal of triangle if intersection
//otherwise returns vec(-1.0,"","")'
float intersectstriangle(Ray ray, std::vector<Vec3> vertices)
{
    
    Vec3 normal = computeNormal(vertices);
    float D = normal.Dot(vertices.at(0));
    float vd =  normal.Dot(ray.direction);//normal dot ray origin
    if(vd > 0) //normal is facing away from camera.  Culled
    {
//        return -1.0;
    }
    else if(vd == 0) //ray is // to plane
    {
        return -1.0;
    }
    
    float vo = normal.Dot(ray.origin) + D;
//    vo = -vo;
    float t = vo/vd;
    if (t < 0) //intersection is behind ray origin
    {
        return -1.0;
    }
    
    Vec3 intersectionPoint = ray.origin.Add(ray.direction.Scale(t));
    Vec3 e0 = vertices.at(1).Subtract(vertices.at(0));
    Vec3 e1 = vertices.at(2).Subtract(vertices.at(1));
    Vec3 e2 = vertices.at(0).Subtract(vertices.at(2));
    Vec3 C0 = intersectionPoint.Subtract(vertices.at(0));
    Vec3 C1 = intersectionPoint.Subtract(vertices.at(1));
    Vec3 C2 = intersectionPoint.Subtract(vertices.at(2));
    Vec3 cp1 = e0.Cross(C0);
    Vec3 cp2 = e1.Cross(C1);
    Vec3 cp3 = e2.Cross(C2);
    if(normal.Dot(cp1) > 0 &&
       normal.Dot(cp2) > 0 &&
       normal.Dot(cp3) > 0)
    {
        return t;
    }
    return -1.0;
//    std::vector<float> projectedIntersectionPoint = {};
//    std::vector<std::vector<float>> projectedtriangleVertices = {};
//
//    if (abs(normal.x) >= abs(normal.y) && abs(normal.x) >= abs(normal.z)) //normal.x has largest mag
//    {
//        projectedIntersectionPoint.push_back(intersectionPoint.y);
//        projectedIntersectionPoint.push_back(intersectionPoint.z);
//        for(int i = 0; i < vertices.size(); i++)
//        {
//            Vec3 curVertex = vertices.at(i);
//            std::vector<float> vertex = {curVertex.y, curVertex.z};
//            projectedtriangleVertices.push_back(vertex);
//        }
//    }
//    else if(abs(normal.y) >= abs(normal.x) && abs(normal.y) >= (normal.z)) //normal.y has largest mag
//    {
//        projectedIntersectionPoint.push_back(intersectionPoint.x);
//        projectedIntersectionPoint.push_back(intersectionPoint.z);
//        for(int i = 0; i < vertices.size(); i++)
//        {
//            Vec3 curVertex = vertices.at(i);
//            std::vector<float> vertex = {curVertex.x, curVertex.z};
//            projectedtriangleVertices.push_back(vertex);
//        }
//    }
//    else //normal.z has largest mag
//    {
//        projectedIntersectionPoint.push_back(intersectionPoint.x);
//        projectedIntersectionPoint.push_back(intersectionPoint.y);
//        for(int i = 0; i < vertices.size(); i++)
//        {
//            Vec3 curVertex = vertices.at(i);
//            std::vector<float> vertex = {curVertex.x, curVertex.y};
//            projectedtriangleVertices.push_back(vertex);
//        }
//    }
//
//    for(int i = 0; i < projectedtriangleVertices.size(); i++) //translate all vertices
//    {
//        std::vector<float> curVertex = projectedtriangleVertices.at(i);
//        curVertex.at(0) = curVertex.at(0)- projectedIntersectionPoint.at(0);
//        curVertex.at(1) = curVertex.at(1)- projectedIntersectionPoint.at(1);
//    }
//
//    bool isInside = isInsideTriangle(projectedtriangleVertices);
//
    

    
//    return t;
}

//returns -1.0 if it doesn't intersect sphere
float intersectsSphere(Ray ray, std::vector<Vec3> location)
{
    Vec3 oc = ray.origin.Subtract(location.at(0));
    float A = ray.direction.Dot(ray.direction);
    float B = 2.0 * ray.direction.Dot(oc);
    float R = location.at(1).x;
    float C = oc.Dot(oc) - R;
    float discriminant = B*B - 4*A*C;
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
        return ((-B + sqrt(discriminant))/ (2*A));
    }
}

Vec3 calculateColor(Vec3 normal, Shape shape, Ray ray, bool shadow)
{
    if(shadow)
    {
        return shape.color.Multiply(ambientColor);

    }
    normal = normal.Normalize();
    Vec3 ambient = shape.color.Multiply(ambientColor);
    Vec3 diffuse = shape.color.Multiply(lightColor);
    float ndotL = normal.Dot(directionToLight);
    if (ndotL <0)
    {
        ndotL = 0;
    }
    diffuse = diffuse.Scale(ndotL);
    
    
    
    Vec3 V = Vec3(-ray.direction.x, -ray.direction.y, -ray.direction.z);
//    Vec3 V = ray.direction;
    float ndotLight = normal.Dot(directionToLight);
    ndotLight *= 2;
    Vec3 R = normal.Scale(ndotLight);
    R = directionToLight.Subtract(R);
    float VdotR = V.Dot(R);
    VdotR = std::pow(VdotR, shape.phong);
    Vec3 finalSpec = shape.specular.Scale(VdotR);
//    finalSpec.Scale(4);
    
//
//    vec3 lightDir = normalize(lightPos - fragPos);
//    vec3 lightVec = normalize(lightDir);
//    float ndotl = dot(normalVec, lightVec);
//    vec3 viewDir = normalize(viewPos - fragPos);
//    vec3 reflectDir = reflect(-lightDir, normalVec);
//    float refl = dot(viewDir, reflectDir);

    
    //cs= Os* (𝑉∙𝑅)^p
    //Os= the specular color of the object
    //V = the direction to the viewer (camera)
    //R = the reflection vector from the light source
       // bounced off of the object
    // reflect (I,N) returns I - 2.0* dot(N,I) * N
    //p = the Phong exponent
    
    
    Vec3 toReturn =  diffuse.Add(ambient).Add(finalSpec);
    if (toReturn.x > 1)
    {
        toReturn.x =1;
    }
    if (toReturn.y > 1)
    {
        toReturn.y = 1;
    }
    if (toReturn.z > 1)
    {
        toReturn.z =1;
    }
    return toReturn;
}

Vec3 calculateRay(Ray ray, std::vector<Shape> shapes, bool shadow)
{
    float cur_z_depth = -100000;
    float index = -1;
    float cur_t_intersect;
    for(int i =0; i < shapes.size(); i++)
    {
        float t_intersect;
        if (shapes.at(i).shapeType == 0)
        {
            t_intersect = intersectsSphere(ray, shapes.at(i).location);
        }
        else if (shapes.at(i).shapeType == 1)
        {
            t_intersect = intersectstriangle(ray, shapes.at(i).location);
        }
        else
        {
            std::cout << "Error.  Invalid shapetype" << std::endl;
            return Vec3(-1,-1,-1);
        }

        if (t_intersect > 0)
        {
            Vec3 intersectionPoint = ray.origin.Add(ray.direction.Scale(t_intersect));
            if (intersectionPoint.z > cur_z_depth)
            {
                index = i;
                cur_t_intersect = t_intersect;
                cur_z_depth = intersectionPoint.z;
            }
        }
    }

    if(index == -1) //no intersections
    {
        return backgroundColor;
    }

    if(shapes.at(index).shapeType == 0)
    {
        Vec3 intersectionPoint = ray.origin.Add(ray.direction.Scale(cur_t_intersect));
        Vec3 normal = intersectionPoint.Subtract(shapes.at(index).location.at(0));
        normal = normal.Normalize();
        if(!shadow)
        {
            if(shapes.at(index).shapeMaterial == 1) // reflective.  Cast new ray
            {
                float reflectionAngle = 2.0 * normal.Dot(ray.direction);
                normal = normal.Scale(reflectionAngle);
                Vec3 reflection = ray.direction.Subtract(normal).Normalize();
                Vec3 newOrigin = intersectionPoint.Add(reflection.Scale(.0001));
                Ray ray = Ray(newOrigin, reflection);
                return calculateRay(ray, shapes, false).Scale(0.75);
//               I - 2.0 * dot(N, I) * N
            }
            Vec3 smallPerturb = directionToLight.Scale(0.1);
            Vec3 newOrigin = intersectionPoint.Add(smallPerturb);
            Ray shadowRay = Ray(newOrigin, directionToLight);
            Vec3 shadowResult = calculateRay(shadowRay, shapes, true);
            if(shadowResult.x != backgroundColor.x || shadowResult.y != backgroundColor.y || shadowResult.z != backgroundColor.z)
            {
                return calculateColor(normal, shapes.at(index), ray, true);

            }
            else
            {
                return calculateColor(normal, shapes.at(index), ray, false);

            }
        }
        else
        {
            return Vec3(1.0,0.1,0.3376);
        }
        //
    }
    else
    {
        if(!shadow)
        {
            Vec3 intersectionPoint = ray.origin.Add(ray.direction.Scale(cur_t_intersect));
            Vec3 smallPerturb = directionToLight.Scale(0.1);
            Vec3 newOrigin = intersectionPoint.Add(smallPerturb);
            Ray shadowRay = Ray(newOrigin, directionToLight);
            Vec3 shadowResult = calculateRay(shadowRay, shapes, true);
            if(shadowResult.x != backgroundColor.x || shadowResult.y != backgroundColor.y || shadowResult.z != backgroundColor.z)
            {
                return calculateColor(computeNormal(shapes.at(index).location), shapes.at(index), ray, true);

            }
            else
            {
                return calculateColor(computeNormal(shapes.at(index).location), shapes.at(index), ray, false);

            }
        }
        else
        {
                return Vec3(1.0,0.1,0.3376);

        }
         
    }
}

int main(int argc, const char * argv[]) {
    
    int numPixelsW = 512;
    int numPixelsH = 512;
    bool scenell = false;
    int fov;
    Vec3 cameraPos;
    float distToScreen;
    std::string fileName;
    std::vector<Shape> shapes;
    if(scenell)
    {
        fov = 55;
        cameraPos = Vec3(0,0,1.2);  //look from
        distToScreen = 1.2f;
        fileName = "scenell.ppm";
        shapes = initializeShapesScenell();

    }
    else
    {
        fov = 28;
        cameraPos = Vec3(0,0,1.0).Normalize();  //look from
        distToScreen = 1.0f;
        fileName = "custom.ppm";
        shapes = initializeShapesCustom();

    }

    float screenWidth = 2* tan(fov * M_PI/180) * distToScreen;
    float pixelWidth = screenWidth/numPixelsW;
    //assuming square image plane
    float pixelHeight = screenWidth/numPixelsH;
    float screenleftx =  -screenWidth/2;
    float screenTopy = screenWidth/2;
    Vec3 screenLeft = Vec3(screenleftx , 0,0);
    Vec3 screenTop = Vec3(0,screenTopy,0);
    std::cout <<"screenLeft = " << screenLeft.x << " screen top = " << screenTop.y << std::endl;
    std::ofstream imageFile = initializeImageFile(fileName, numPixelsW, numPixelsH);
    imageFile.flush();
    
    for (int i = 0; i < numPixelsH; i++)
    {
        float pixelCenterY = screenTop.y - (i*pixelHeight) - (0.5*pixelHeight);
        for(int j = 0; j < numPixelsW; j++)
        {
            float pixelCenterX = screenLeft.x + (j*pixelWidth) + (0.5*pixelWidth);
            Vec3 pixelCenter = Vec3(pixelCenterX, pixelCenterY,0);
//            std::cout << "X : " << pixelCenterX << " Y : " << pixelCenterY << std::endl;
            Ray ray = Ray(cameraPos, pixelCenter.Subtract(cameraPos).Normalize());
            Vec3 outColor = calculateRay(ray, shapes, false).Scale(255);
//            std::cout << outColor.x << " " << outColor.y << " " << outColor.z << std::endl;
            imageFile << floor(outColor.x) << " " << floor(outColor.y) << " " << floor(outColor.z) << std::endl;
        }
    }
    imageFile.flush();
    std::cout << "Hello, World!\n";
    return 0;
}
