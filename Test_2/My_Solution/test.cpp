#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>
#include <iostream>
#include "Cylinder.h"
    
int main()
{
    const double HEIGHT{ 15.5 };

    /// Task 3: Cylinder instance creation
    Cylinder c0{ HEIGHT, M_PI }; // base height and a radius

    const double EPS{ 0.05 };

    /// Task 4: Retrieve height
    assert(std::abs(HEIGHT - c0.get_height()) < EPS);

    /// Task 4: Retrieve base radius
    assert(std::abs(M_PI - c0.get_radius()) < EPS);

//    / Task 5: Retrieve volume
    assert(std::abs((480.6 - c0.get_volume())*EPS) < EPS);

    /// Task 5: Retrieve base area
    assert(std::abs((31 - c0.get_base_area())*EPS) < EPS);

    /// Task 5: Retrieve lateral area
    assert(std::abs((306 - c0.get_lateral_area())*EPS) < EPS);

    /// Task 5: Retrieve total surface area
    assert(std::abs((337 - c0.get_total_area())*EPS) < EPS);

    std::cout << "OK\n";

    return 0;
}
