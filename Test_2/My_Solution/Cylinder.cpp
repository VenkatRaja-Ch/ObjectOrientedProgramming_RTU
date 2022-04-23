// Add required C++ statements to define the class Cylinder

#include "Cylinder.h"

Cylinder :: Cylinder () {
    _height = 0.0;
    _radius = 0.0;
}

Cylinder :: Cylinder (double h, double r) {
    _height = h;
    _radius = r;
}

Cylinder::~Cylinder(){};

float Cylinder::getHeight (){ return (float)_height; }
float Cylinder::getRadius () { return (float)_radius; }
void Cylinder::setHeight( float height ) { _height = height; }
void Cylinder::setRadius( float radius ) { _radius = radius; }

float Cylinder::get_volume(){
    return 3.14*_height*_radius*_radius;
}

float Cylinder::get_base_area(){
    
    return 3.14*_radius*_radius;
}

float Cylinder::get_lateral_area(){
    
    return 2*3.14*_radius*_height;
}
float Cylinder::get_total_area(){
    
    return (get_base_area() + get_lateral_area());
}
