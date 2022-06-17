#ifndef LINE3D_H
#define LINE3D_H

#include "Line2D.h"
#include "Point3D.h"

// Definition of class Line3D, sub-class of Line2D
class Line3D : public Line2D
{
    private:
        Point3D pt1;
        Point3D pt2;
    
    protected:
        void setLength();

    public:
        // Definition of constructors
        Line3D();
        Line3D(Point3D, Point3D);

        // Definition of accessor methods
        Point3D getPt1() const;
        Point3D getPt2() const;
        
        // Definition of mutator methods
        void setPt1(Point3D);
        void setPt2(Point3D);

        // Definition of overload operator
        bool operator==(const Line3D&);

        // Definition of comparator function
        static bool compareEqualLines(const Line3D&, const Line3D&);
        static bool compareLinesAscending(const Line3D&, const Line3D&);
        static bool comparePoint1Ascending(const Line3D&, const Line3D&);
        static bool comparePoint1Descending(const Line3D&, const Line3D&);
        static bool comparePoint2Ascending(const Line3D&, const Line3D&);
        static bool comparePoint2Descending(const Line3D&, const Line3D&);
        static bool compareLengthAscending(const Line3D&, const Line3D&);
        static bool compareLengthDescending(const Line3D&, const Line3D&);
};

#endif