#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <utility>
#include <cmath>
#include <algorithm>
#include "Point2D.h"
using namespace std;

// Implement constructors
Point2D::Point2D()
{
    x = 0;
    y = 0;
    setDistFrOrigin();
}

Point2D::Point2D(int x, int y)
{
    this->x = x;
    this->y = y;
    setDistFrOrigin();
}

Point2D::Point2D(const Point2D& pt)
{
    x = pt.x;
    y = pt.y;
    distFrOrigin = pt.distFrOrigin;
}

// Implement accessor methods
int Point2D::getX() const
{
    return x;
}

int Point2D::getY() const
{
    return y;
}

double Point2D::getScalarValue() const
{
    return distFrOrigin;
}

// Implement mutator methods
void Point2D::setX(int x)
{
    this->x = x;
    setDistFrOrigin();
}

void Point2D::setY(int y)
{
    this->y = y;
    setDistFrOrigin();
}

// Implement overload operator
bool Point2D::operator==(const Point2D& pt)
{
    return (x == pt.x && y == pt.y);
}

// Implement method to compute and set value for distance from the point from origin
void Point2D::setDistFrOrigin()
{
    distFrOrigin = sqrt(pow(x, 2) + pow(y, 2));
}

// Implement comparator functions
bool Point2D::compareEqualPoints(const Point2D& p1, const Point2D& p2)
{
    return (p1.x == p2.x && p1.y == p2.y);
}

bool Point2D::comparePointsAscending(const Point2D& p1, const Point2D& p2)
{
    if (p1.x != p2.x)
        return p1.x < p2.x;
    else
        return p1.y < p2.y;
}

bool Point2D::comparePointsDescending(const Point2D& p1, const Point2D& p2)
{
    if (p1.x != p2.x)
        return p1.x > p2.x;
    else
        return p1.y > p2.y;
}

bool Point2D::compareXAscending(const Point2D& p1, const Point2D& p2)
{
    return p1.x < p2.x;
}

bool Point2D::compareXDescending(const Point2D& p1, const Point2D& p2)
{
    return p1.x > p2.x;
}

bool Point2D::compareYAscending(const Point2D& p1, const Point2D& p2)
{
    return p1.y < p2.y;
}

bool Point2D::compareYDescending(const Point2D& p1, const Point2D& p2)
{
    return p1.y > p2.y;
}

bool Point2D::compareDistAscending(const Point2D& p1, const Point2D& p2)
{
    return p1.distFrOrigin < p2.distFrOrigin;
}

bool Point2D::compareDistDescending(const Point2D& p1, const Point2D& p2)
{
    return p1.distFrOrigin > p2.distFrOrigin;
}