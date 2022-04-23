#ifndef Cylinder_h
#define Cylinder_h


class Cylinder{
    
private:
    float _height;
    float _radius;

public:
    float getHeight ();
    float getRadius ();
    void setHeight( float height );
    void setRadius( float radius );
    
    float get_volume();
    float get_base_area();
    float get_lateral_area();
    float get_total_area();
    
    Cylinder();
    Cylinder( double h, double r);
    ~Cylinder();
};
#endif /* Cylinder_h */
