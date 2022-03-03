#ifndef INVENTORY
#define INVENTORY

#include "Bicycle.h" // must be replaced, e.g. to "Bicycle"

class Inventory
{
public:
    // Initializes the inventory
    void init() { _count = 0; }

    // Returns the current number of abstraction objects
    size_t get_count() { return _count; }

    // Returns stored abstraction object by its index or default object if index is invalid
    Bicycle get_item(size_t i) { return (i < _count) ? _items[i] : Bicycle{}; }

    // From passed property values, creates and adds new abstraction object in an array _items
    // (replace parameters to match your property types and identifiers)
    void add_item(int id, string type, double price);

    // Looks for a matching abstraction object and returns the first found or default object
    Bicycle find_item(Bicycle query);

private:
    // The maximum number of abstraction objects that can be stored
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Bicycle _items[Inventory::MAX_SIZE];

    // The number of currently stored abstraction objects in the array _items
    size_t _count;
};

#endif
