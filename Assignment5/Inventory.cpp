// Assignment: 5

#include "Inventory.h"
#include <cmath>

// The parameters must match with the class declaration
void Inventory::add_item( unsigned id, string organiser, shared_ptr <const TourSpec> spec )
{
    
    if (_count < Inventory::MAX_SIZE)
    {

        Tour new_item ( id, organiser, spec );
        Tour found = find_item(new_item);
        
        // Assignment:03 - Task: 10
        bool itemNotFound = (id != found.get_tourID());
        assert(1 == itemNotFound);
        _items[_count] = new_item;
        _count ++;
        
//        if(itemNotFound)
//        {
//            _items[_count] = new_item;
//            _count++;
//        }
    }
}

Tour Inventory::find_item( const Tour & query ) const
{
    for(size_t index = 0; index < _count; index++){
        
        // for integer and boolean type property
        bool differentTourID = query.get_tourID()!=0 &&   query.get_tourID()!=_items[index].get_tourID();
        
        bool differentTourOrganiser = query.get_tourOrganiser()!="" && query.get_tourOrganiser()!=_items[index].get_tourOrganiser();
        
        if(differentTourID)
            continue;
        if(differentTourOrganiser)
            continue;
        
        // check specification properties
        if(   query.get_tourSpec()        // check for not null
           && _items[index].get_tourSpec()  // check for not null
           && _items[index].get_tourSpec() ->
              matches(*query.get_tourSpec()) )    // check if item exists
            return _items[index];
    }
    
    return Tour{};
}

// for function overloading part
Tour Inventory::find_item(const TourSpec & spec_query) const
{
    
    for(size_t index = 0; index < _count; index++)
    {
        // check specification properties
        // if in current item the spec() exists then check for the item
        if( _items[index].get_tourSpec()  // check for not null
           && _items[index].get_tourSpec() -> matches(spec_query) )    // check if item exists
            return _items[index];
    }
    
    return Tour{};
}
