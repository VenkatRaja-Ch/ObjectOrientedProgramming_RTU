#ifndef Tour_h
#define Tour_h

#include <string>

using namespace std;

// Student Name: Venkat Raja Ch
// Student ID: 201ADB022
// abstraction: Tour
// propertied which could be abstracted: id, Organiser, Starting date, Ending date, Destination, Price

class Tour {
    
public:
    
    enum class IsInternational { ANY, YES, NO };
    
    
    void init( int id, string organiser, string destination, double price, string startingDate, string endingDate, Tour::IsInternational isTourInternational);
    
    int get_tourID() { return _tourID; }
    string get_tourOrganiser() { return _tourOrganiser; }
    string get_tourDestination() { return _tourDestination; }
    double get_tourPrice() { return _tourPrice; }
    string get_tourStartingDate() { return _tourStartingDate; }
    string get_tourEndingDate() { return _tourEndingDate; }

    
    Tour::IsInternational get_isTourInternational() { return _isTourInternational; }
    
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
