#ifndef POINT_H
#define POINT_H


class Point
{

public:
    int x,y;
    Point(){}

    Point(int x, int y){
        this->x = x;
        this->y = y;
    };

     bool operator<(const Point &other) const
    {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

#endif // POINT_H
