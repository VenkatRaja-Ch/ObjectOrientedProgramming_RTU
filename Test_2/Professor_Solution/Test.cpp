#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include <iostream>
#include "Cylinder.h"

int main()
{
    const double HEIGHT{ 15.5 };
    
    // Task 3: Cylinder instance creation
    Cylinder c0{ HEIGHT, M_PI }; // base height and a radius
    
    const double EPS{ 0.05 };
    
    //TASK 4: Retrieve height
    assert( std::abs( HEIGHT - c0.get_height() ) < EPS );
    
    //TASK 4: Retrieve base radius
    assert( std::abs( M_PI - c0.get_radius() ) < EPS );
    
    //TASK 5: Retrieve Volume
    assert( std::abs( 480.6 - c0.get_volume() ) < EPS );
    
    //TASK 5: Retrieve Base Area
    assert( std::abs( 31 - c0.get_base_area() ) < EPS );
    
    //TASK 5: Retrieve Lateral Area
    assert( std::abs( 306 - c0.get_lateral_area() ) < EPS );
    
    //TASK 5: Retrieve Total Surface Area
    assert( std::abs( 368 - c0.get_total_area() ) < EPS );
    
    std::cout << "OK\n";
    return 0;
}
