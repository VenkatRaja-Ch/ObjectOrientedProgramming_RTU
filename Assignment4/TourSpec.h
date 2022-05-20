// Assignment 4
 
#ifndef TourSpec_h
#define TourSpec_h

#include <cstddef>
#include <string>
using namespace std;

class TourSpec {
public:
    // enumeration class
    enum class IsInternational { ANY, YES, NO };
    
    // object's default constructor
    TourSpec() = default;
    
    // object's parameterized constructor
    TourSpec(IsInternational isTourInternational, double price, string destination, string startingDate, string endingDate)
    :
        _isTourInternational { isTourInternational },
        _tourPrice{ price },
        _tourDestination{ destination },
        _tourStartingDate{ startingDate },
        _tourEndingDate{ endingDate } {}
    
    // getter functions
    IsInternational get_isTourInternational() const { return _isTourInternational; }
    double get_tourPrice() const { return _tourPrice; }
    string get_tourDestination() const { return _tourDestination; }
    string get_tourStartingDate() const { return _tourStartingDate; }
    string get_tourEndingDate() const { return _tourEndingDate; }

    // another C++ idiom to return an enumeration value as a string
    const std::string & get_isTourInternational_as_String () const {
        static const std::string IsInternational_S[] { "ANY", "YES", "NO" };
        return IsInternational_S[ (std::size_t)_isTourInternational ];
    }

private:
    double _tourPrice;
    string _tourDestination;
    string _tourStartingDate;
    string _tourEndingDate;
    IsInternational _isTourInternational;
};

#endif
