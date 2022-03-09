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
    void init( int ids, Tour::TourOrganiser organiser, string destination, double price, string startingDate, string endingDate, bool isInternational); //added now
    
    int get_tourID() { return _tourId; }
    
    //string get_tourOrganiser() { return _tourOrganiser; }
    
    enum class TourOrganiser {ANY, EXPEDIA, BALTIC_TRAVEL, GO_TRAVEL};
    
    string get_tourDestination() { return _tourDestination; }
    double get_tourPrice() { return _tourPrice; }
    string get_tourStartingDate() { return _tourStartingDate; }
    string get_tourEndingDate() { return _tourEndingDate; }
    bool get_isTourInternational() { return _isTourInternational; }
    
    void init(int id, Tour::TourOrganiser organiser, string destination, double price, string startingDate, string endingDate, bool isTourInternational);
    
    Tour::TourOrganiser get_tourOrganiser() { return _tourOrganiser; }

private:
    Tour::TourOraganiser _tourOrganiser;
    
    int _tourId;
    string _tourDestination;
    double _tourPrice;
    string _tourStartingDate;
    string _tourEndingDate;
    bool _isTourInternational;
};

#endif
 
