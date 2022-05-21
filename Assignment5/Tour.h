// Assignment: 5

#ifndef Tour_h
#define Tour_h

#include <string>
#include <memory>

#include "TourSpec.h"
using namespace std;

// Student Name: Venkat Raja Ch
// Student ID: 201ADB022
// abstraction: Tour

class Tour {
    
public:
    // object's default constructor
    Tour() = default;
    
    // object' parameterized constructor
    Tour( unsigned id, string organiser, shared_ptr <const TourSpec> spec ) :
        _tourID{ id },
        _tourOrganiser{ organiser },
        _spec{ spec } { }
    
    // getter functions
    unsigned get_tourID() const { return _tourID; }
    string get_tourOrganiser() const { return _tourOrganiser; }
    shared_ptr <const TourSpec> get_tourSpec() const { return _spec; }
    
private:
    unsigned _tourID;
    string _tourOrganiser;
    shared_ptr < const TourSpec > _spec;
};

#endif
