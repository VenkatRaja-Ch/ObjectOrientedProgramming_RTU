// Assignment: 4

#ifndef Inventory_h
#define Inventory_h

#include "Tour.h"
using namespace std;

class Inventory {
    
public:
    // initialise the inventory
    Inventory() : _count ( 0U ) {}  // Assignment4 -   Task 3
    
    // Returns the current number of abstraction objects
    size_t get_count() const { return _count; }
    
    // Returns stored abstraction object by its index or default object if index is invalid
    Tour get_item( size_t index ) const { return (index < _count) ? _items[index] : Tour{}; }
    
    
    
    // From passed property values, creates and adds new abstraction object in an array _items
    void add_item( unsigned id, const string &organiser, const TourSpec & spec);

    
    
    // Look for a matching abstraction object and returns the first found or default object
    Tour find_item(const Tour & query ) const;
    
    // for function overloading part
    Tour find_item(const TourSpec & spec_query ) const;
    
private:
    // the maximum number of abstraction object that can be stored
    static const size_t MAX_SIZE{ 10 };
    
    // an array for storing abstraction objects
    Tour _items[ Inventory::MAX_SIZE ];
    
    // the number of currently stored abstraction objects in the array _items
    size_t _count;
};

#endif
