#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <utility>
#include <cmath>
#include <algorithm>
#include "Line2D.h"
using namespace std;

// Implement constructors
Line2D::Line2D()
{
    pt1 = Point2D();
    pt2 = Point2D();
    setLength();
}

Line2D::Line2D(Point2D pt1, Point2D pt2)
{
    this->pt1 = pt1;
    this->pt2 = pt2;
    setLength();
}

// Implement accessor methods
Point2D Line2D::getPt1() const
{
    return pt1;
}

Point2D Line2D::getPt2() const
{
    return pt2;
}

double Line2D::getScalarValue() const
{
    return length;
}

// Implement mutator methods
void Line2D::setPt1(Point2D pt1)
{
    this->pt1 = pt1;
    setLength();
}

void Line2D::setPt2(Point2D pt2)
{
    this->pt2 = pt2;
    setLength();
}

// Implement overload operator
bool Line2D::operator==(const Line2D& line2)
{
    return (pt1 == line2.pt1 && pt2 == line2.pt2);
}

// Implement method to compute and set value for distance between point 1 to point 2
void Line2D::setLength()
{
    length = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2));
}

// Implement comparator functions
bool Line2D::compareEqualLines(const Line2D& l1, const Line2D& l2)
{
    return (Point2D::compareEqualPoints(l1.getPt1(), l2.getPt1()) && Point2D::compareEqualPoints(l1.getPt2(), l2.getPt2()));
}

bool Line2D::compareLinesAscending(const Line2D& l1, const Line2D& l2)
{
    Point2D l1p1 = l1.getPt1();
    Point2D l1p2 = l1.getPt2();
    Point2D l2p1 = l2.getPt1();
    Point2D l2p2 = l2.getPt2();

    // Check if line 1's point 1 is equal to line 2's point 1
    if (!(Point2D::compareEqualPoints(l1p1, l2p1)))
        return Point2D::comparePointsAscending(l1p1, l2p1);
    else
        return Point2D::comparePointsAscending(l1p2, l2p2);
}

bool Line2D::comparePoint1Ascending(const Line2D& l1, const Line2D& l2)
{
    return Point2D::comparePointsAscending(l1.getPt1(), l2.getPt1());
}

bool Line2D::comparePoint1Descending(const Line2D& l1, const Line2D& l2)
{
    return Point2D::comparePointsDescending(l1.getPt1(), l2.getPt1());
}

bool Line2D::comparePoint2Ascending(const Line2D& l1, const Line2D& l2)
{
    return Point2D::comparePointsAscending(l1.getPt2(), l2.getPt2());
}

bool Line2D::comparePoint2Descending(const Line2D& l1, const Line2D& l2)
{
    return Point2D::comparePointsDescending(l1.getPt2(), l2.getPt2());
}

bool Line2D::compareLengthAscending(const Line2D& l1, const Line2D& l2)
{
    return l1.getScalarValue() < l2.getScalarValue();
}

bool Line2D::compareLengthDescending(const Line2D& l1, const Line2D& l2)
{
    return l1.getScalarValue() > l2.getScalarValue();
}