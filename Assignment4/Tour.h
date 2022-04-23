// Assignment: 4

#ifndef Tour_h
#define Tour_h

#include <string>
#include "TourSpec.h"
using namespace std;

// Student Name: Venkat Raja Ch
// Student ID: 201ADB022
// abstraction: Tour
// propertied which could be abstracted: id, Organiser, Starting date, Ending date, Destination, Price

class Tour {
    
public:
    
    Tour() = default;
    Tour( unsigned id, string organiser, string destination, double price, string startingDate, string endingDate, const TourSpec & spec) :
        _tourID{ id },
        _tourOrganiser{ organiser },
        _tourDestination{ destination },
        _tourPrice{ price },
        _tourStartingDate{ startingDate },
        _tourEndingDate{ endingDate },
        _spec{ spec } { }
    
    unsigned get_tourID() const { return _tourID; }
    string get_tourOrganiser() const { return _tourOrganiser; }
    string get_tourDestination() const { return _tourDestination; }
    double get_tourPrice() const { return _tourPrice; }
    string get_tourStartingDate() const { return _tourStartingDate; }
    string get_tourEndingDate() const { return _tourEndingDate; }
    TourSpec get_tourSpec() const { return _spec; }
    
private:
    unsigned _tourID;
    string _tourOrganiser;
    string _tourDestination;
    double _tourPrice;
    string _tourStartingDate;
    string _tourEndingDate;
    TourSpec _spec;
};

#endif
