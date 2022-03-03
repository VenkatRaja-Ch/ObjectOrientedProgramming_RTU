#include "Tour.h"

#include <iostream>
using namespace std;

void::Tour::init(int id, string organiser, string destination, double price, string startingDate, string endingDate, bool isInternational) {
    
    _tourID = id;
    _tourOrganiser = organiser;
    _tourDestination = destination;
    _tourPrice = price;
    _tourStartingDate = startingDate;
    _tourEndingDate = endingDate;
    _isTourInternational = isInternational;
}
 
