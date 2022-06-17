#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <utility>
#include <cmath>
#include <algorithm>
#include "Line3D.h"
using namespace std;

// Implement constructors
Line3D::Line3D()
{
    pt1 = Point3D();
    pt2 = Point3D();
    setLength();
}

Line3D::Line3D(Point3D pt1, Point3D pt2)
{
    this->pt1 = pt1;
    this->pt2 = pt2;
    setLength();
}

// Implement accessor methods
Point3D Line3D::getPt1() const
{
    return pt1;
}

Point3D Line3D::getPt2() const
{
    return pt2;
}

// Implement mutator methods
void Line3D::setPt1(Point3D pt1)
{
    this->pt1 = pt1;
    setLength();
}

void Line3D::setPt2(Point3D pt2)
{
    this->pt2 = pt2;
    setLength();
}

// Implement overload operator
bool Line3D::operator==(const Line3D& line2)
{
    return (pt1 == line2.pt1 && pt2 == line2.pt2);
}

// Implement method to compute and set value for distance between point 1 to point 2
void Line3D::setLength()
{
    length = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2) + pow(pt1.getZ() - pt2.getZ(), 2));
}

// Implement comparator functions
bool Line3D::compareEqualLines(const Line3D& l1, const Line3D& l2)
{
    return (Point3D::compareEqualPoints(l1.getPt1(), l2.getPt1()) && Point3D::compareEqualPoints(l1.getPt2(), l2.getPt2()));
}

bool Line3D::compareLinesAscending(const Line3D& l1, const Line3D& l2)
{
    Point3D l1p1 = l1.getPt1();
    Point3D l1p2 = l1.getPt2();
    Point3D l2p1 = l2.getPt1();
    Point3D l2p2 = l2.getPt2();

    // Check if line 1's point 1 is equal to line 2's point 1
    if (!(Point3D::compareEqualPoints(l1p1, l2p1)))
        return Point3D::comparePointsAscending(l1p1, l2p1);
    else
        return Point3D::comparePointsAscending(l1p2, l2p2);
}

bool Line3D::comparePoint1Ascending(const Line3D& l1, const Line3D& l2)
{
    return Point3D::comparePointsAscending(l1.getPt1(), l2.getPt1());
}

bool Line3D::comparePoint1Descending(const Line3D& l1, const Line3D& l2)
{
    return Point3D::comparePointsDescending(l1.getPt1(), l2.getPt1());
}

bool Line3D::comparePoint2Ascending(const Line3D& l1, const Line3D& l2)
{
    return Point3D::comparePointsAscending(l1.getPt2(), l2.getPt2());
}

bool Line3D::comparePoint2Descending(const Line3D& l1, const Line3D& l2)
{
    return Point3D::comparePointsDescending(l1.getPt2(), l2.getPt2());
}

bool Line3D::compareLengthAscending(const Line3D& l1, const Line3D& l2)
{
    return l1.getScalarValue() < l2.getScalarValue();
}

bool Line3D::compareLengthDescending(const Line3D& l1, const Line3D& l2)
{
    return l1.getScalarValue() > l2.getScalarValue();
}