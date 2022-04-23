// Assignment 4
 
#ifndef TourSpec_h
#define TourSpec_h

#include <cstddef> // for std::size_t
#include <string>

class TourSpec {
public:
    //enum class Type { ANY, MTB, STREET, BEACH, BMX };
    enum class IsInternational { ANY, YES, NO };
    
    //BicycleSpec() = default;
    TourSpec() = default;
    
    TourSpec(IsInternational isTourInternational) : _isTourInternational { isTourInternational } {}
//    //BicycleSpec(Type type, ..)
//        : _type{ type }, .. { }
    
    IsInternational get_isTourInternational() const { return _isTourInternational; }
    //Type get_type() const {  return _type;  }

    // another C++ idiom to return an enumeration value as a string
    const std::string & get_isTourInternational_as_String () const {
        static const std::string IsInternational_S[] { "ANY", "YES", "NO" };
        return IsInternational_S[ (std::size_t)_isTourInternational ];
    }
//        const std::string & get_type_as_string() const {
//        static const std::string Type_S[] { "Any", "MTB", "Street", "Beach", "BMX" };
//        return Type_S[(std::size_t)_type];
//    }

private:
    IsInternational _isTourInternational;
    //Type _type;

};

#endif
