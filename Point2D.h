#ifndef POINT2D_H
#define POINT2D_H

// Definition of class Point2D
class Point2D
{
    protected:
        int x;
        int y;
        double distFrOrigin;
        virtual void setDistFrOrigin();

    public:
        // Definition of constructors
        Point2D();
        Point2D(int, int);
        Point2D(const Point2D&);

        // Defintion of accessor methods
        int getX() const;
        int getY() const;
        double getScalarValue() const;

        // Definition of mutator methods
        void setX(int);
        void setY(int);

        // Definition of overload operator
        bool operator==(const Point2D&);

        // Definition of comparator functions
        static bool compareEqualPoints(const Point2D&, const Point2D&);
        static bool comparePointsAscending(const Point2D&, const Point2D&);
        static bool comparePointsDescending(const Point2D&, const Point2D&);
        static bool compareXAscending(const Point2D&, const Point2D&);
        static bool compareXDescending(const Point2D&, const Point2D&);
        static bool compareYAscending(const Point2D&, const Point2D&);
        static bool compareYDescending(const Point2D&, const Point2D&);
        static bool compareDistAscending(const Point2D&, const Point2D&);
        static bool compareDistDescending(const Point2D&, const Point2D&);
};

#endif