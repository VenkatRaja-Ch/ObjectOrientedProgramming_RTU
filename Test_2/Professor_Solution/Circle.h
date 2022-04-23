#ifndef Circle_h
#define Circle_h

#define _USE_MATH_DEFINES
#include <cmath>

class Circle
{
    
public:
    Circle( double radius )
        : _radius( radius )
    {}
    
    double get_radius() const
    {
        return _radius;
    }
    
    double get_area() const
    {
        return M_PI * _radius * _radius;
    }
    
private:
    const double _radius;
};

#endif
