// Assignment: 3

#ifndef Tour_h
#define Tour_h

#include <string>

using namespace std;

// Student Name: Venkat Raja Ch
// Student ID: 201ADB022
// abstraction: Tour
// propertied which could be abstracted: id (integer) , Organiser (string), Starting date(string), Ending date(string), Destination (string), Price (double)

class Tour {
    
public:
    
    enum class IsInternational { ANY, YES, NO };
    
    
    void init( int id, string organiser, string destination, double price, string startingDate, string endingDate, Tour::IsInternational isTourInternational);
    
    int get_tourID() const { return _tourID; }
    string get_tourOrganiser() const { return _tourOrganiser; }
    string get_tourDestination() const { return _tourDestination; }
    double get_tourPrice() const { return _tourPrice; }
    string get_tourStartingDate() const { return _tourStartingDate; }
    string get_tourEndingDate() const { return _tourEndingDate; }

    
    Tour::IsInternational get_isTourInternational() const { return _isTourInternational; }
    
private:
    int _tourID;
    string _tourOrganiser;
    string _tourDestination;
    double _tourPrice;
    string _tourStartingDate;
    string _tourEndingDate;
    Tour::IsInternational _isTourInternational;
};

#endif
