#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

// Definition of class Point3D, sub-class of Point2D
class Point3D : public Point2D
{
    protected:
        int z;
        void setDistFrOrigin();

    public:
        // Definition of constructors
        Point3D();
        Point3D(int, int, int);
        Point3D(const Point3D&);

        // Definition of accessor methods
        int getZ() const;

        // Definition of mutator methods
        void setZ(int);

        // Definition of overload operator
        bool operator==(const Point3D&);

        // Definition of comparator function
        static bool compareEqualPoints(const Point3D&, const Point3D&);
        static bool comparePointsAscending(const Point3D&, const Point3D&);
        static bool comparePointsDescending(const Point3D&, const Point3D&);
        static bool compareXAscending(const Point3D&, const Point3D&);
        static bool compareXDescending(const Point3D&, const Point3D&);
        static bool compareYAscending(const Point3D&, const Point3D&);
        static bool compareYDescending(const Point3D&, const Point3D&);
        static bool compareZAscending(const Point3D&, const Point3D&);
        static bool compareZDescending(const Point3D&, const Point3D&);
        static bool compareDistAscending(const Point3D&, const Point3D&);
        static bool compareDistDescending(const Point3D&, const Point3D&);
};

#endif
