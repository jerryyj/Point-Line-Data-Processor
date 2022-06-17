#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <utility>
#include <cmath>
#include <algorithm>
#include "Point3D.h"
using namespace std;

// Implement constructors
Point3D::Point3D() : Point2D() // Call parent class default constructor
{
    z = 0;
    setDistFrOrigin();
}

Point3D::Point3D(int x, int y, int z) : Point2D(x, y) // Call parent class other constructor
{
    this->z = z;
    setDistFrOrigin();
}

Point3D::Point3D(const Point3D& pt)
{
    x = pt.x;
    y = pt.y;
    z = pt.z;
    distFrOrigin = pt.distFrOrigin;
}

// Implement accessor methods
int Point3D::getZ() const
{
    return z;
}

// Implement mutator methods
void Point3D::setZ(int z)
{
    this->z = z;
    setDistFrOrigin();
}

// Implement overload operator
bool Point3D::operator==(const Point3D& pt)
{
    return (x == pt.x && y == pt.y && z == pt.z);
}

// Implement method to compute and set value for distance from the point from origin
void Point3D::setDistFrOrigin()
{
    distFrOrigin = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

// Implement comparator function
bool Point3D::compareEqualPoints(const Point3D& p1, const Point3D& p2)
{
    return (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z);
}

bool Point3D::comparePointsAscending(const Point3D& p1, const Point3D& p2)
{
    if (p1.x != p2.x)
        return p1.x < p2.x;
    else if (p1.y != p2.y)
        return p1.y < p2.y;
    else
        return p1.z < p2.z;
}

bool Point3D::comparePointsDescending(const Point3D& p1, const Point3D& p2)
{
    if (p1.x != p2.x)
        return p1.x > p2.x;
    else if (p1.y != p2.y)
        return p1.y > p2.y;
    else
        return p1.z > p2.z;
}

bool Point3D::compareXAscending(const Point3D& p1, const Point3D& p2)
{
    return p1.x < p2.x;
}

bool Point3D::compareXDescending(const Point3D& p1, const Point3D& p2)
{
    return p1.x > p2.x;
}

bool Point3D::compareYAscending(const Point3D& p1, const Point3D& p2)
{
    return p1.y < p2.y;
}

bool Point3D::compareYDescending(const Point3D& p1, const Point3D& p2)
{
    return p1.y > p2.y;
}

bool Point3D::compareZAscending(const Point3D& p1, const Point3D& p2)
{
    return p1.z < p2.z;
}

bool Point3D::compareZDescending(const Point3D& p1, const Point3D& p2)
{
    return p1.z > p2.z;
}

bool Point3D::compareDistAscending(const Point3D& p1, const Point3D& p2)
{
    return p1.distFrOrigin < p2.distFrOrigin;
}

bool Point3D::compareDistDescending(const Point3D& p1, const Point3D& p2)
{
    return p1.distFrOrigin > p2.distFrOrigin;
}