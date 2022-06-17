#ifndef LINE2D_H
#define LINE2D_H

#include "Point2D.h"

// Definition of class Line2D
class Line2D
{
    private:
        Point2D pt1;
        Point2D pt2;

    protected:
        double length;
        virtual void setLength();

    public:
        // Definition of constructors
        Line2D();
        Line2D(Point2D, Point2D);

        // Definition of accesor methods
        Point2D getPt1() const;
        Point2D getPt2() const;
        double getScalarValue() const;

        // Definition of mutator methods
        void setPt1(Point2D);
        void setPt2(Point2D);

        // Definition of overload operator
        bool operator==(const Line2D&);

        // Definition of comparator functions
        static bool compareEqualLines(const Line2D&, const Line2D&);
        static bool compareLinesAscending(const Line2D&, const Line2D&);
        static bool comparePoint1Ascending(const Line2D&, const Line2D&);
        static bool comparePoint1Descending(const Line2D&, const Line2D&);
        static bool comparePoint2Ascending(const Line2D&, const Line2D&);
        static bool comparePoint2Descending(const Line2D&, const Line2D&);
        static bool compareLengthAscending(const Line2D&, const Line2D&);
        static bool compareLengthDescending(const Line2D&, const Line2D&);
};

#endif