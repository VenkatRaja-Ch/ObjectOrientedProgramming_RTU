#ifndef Cylinder_h
#define Cylinder_h


#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"

// METHOD 1:
/*
class Cylinder {
    
public:
    Cylinder( double height, double radius) : _height{ height }, _radius{ radius } {}
    double get_height() const { return _height; }
    double get_radius() const { return _radius; }
    double get_volume() const { return M_PI * _radius * _radius * _height; }
    double get_base_area() const { return M_PI * _radius * _radius; }
    double get_lateral_area() const { return 2 * M_PI * _radius * _height; }
    double get_total_area() const { return 2 * get_base_area() + get_lateral_area(); }
    
private:
    double _radius;
    double _height;
};
*/



//METHOD 2:
class Cylinder {
    
public:
    Cylinder( double height, double radius ) : _height{ height }, _base{ radius } {}
    double get_height() const { return _height; }
    double get_radius() const { return _base.get_radius(); }
    double get_volume() const { return M_PI * _base.get_radius() * _base.get_radius() * _height; }
    double get_base_area() const { return M_PI * _base.get_radius() * _base.get_radius(); }
    double get_lateral_area() const { return 2 * M_PI * _base.get_radius() * _height; }
    double get_total_area() const { return 2 * get_base_area() + get_lateral_area(); }
    
private:
    double _height;
    Circle _base;
};

#endif
