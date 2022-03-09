#include "Tour.h"

#include <iostream>
using namespace std;

void Tour::init(int ids, Tour::TourOrganiser organiser, string destination, double price, string startingDate, string endingDate, bool isInternational) {
    
    Tour::TourOrganiser _tourOrganiser = organiser;
    _tourDestination = destination;
    _tourPrice = price;
    _tourStartingDate = startingDate;
    _tourEndingDate = endingDate;
    _isTourInternational = isInternational;
    _tourId = ids;
}
 
