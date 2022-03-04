#include "Inventory.h"

// The parameters must match with the class declaration
void Inventory::add_item( int id, string organiser, string destination, double price, string startingDate, string endingDate, bool isInternational )
{
    
    if (_count < Inventory::MAX_SIZE)
    {
        
        Tour new_item;
        new_item.init( id, organiser, destination, price, startingDate,endingDate, isInternational );
        _items[_count] = new_item;
        _count ++;
    }
}

Tour Inventory::find_item( Tour query )
{
    for(size_t index = 0; index < _count; index++){
        
        // for integer and boolean type property
        bool differentTourID = query.get_tourID()!=0 && query.get_tourID()!=_items[index].get_tourID();
        bool differntTourPrice = query.get_tourPrice()!=0 && query.get_tourPrice()!=_items[index].get_tourPrice();
        bool differentIsTourInternational = query.get_isTourInternational()!=0 && query.get_isTourInternational()!=_items[index].get_isTourInternational();

        // for string type property
        bool differentTourOrganiser = query.get_tourOrganiser()!="" && query.get_tourOrganiser()!=_items[index].get_tourOrganiser();
        bool differentTourDestination = query.get_tourDestination()!="" && query.get_tourDestination()!=_items[index].get_tourDestination();
        bool differentStartingDate = query.get_tourStartingDate()!="" && query.get_tourStartingDate()!=_items[index].get_tourStartingDate();
        bool differentEndingDate = query.get_tourEndingDate()!="" && query.get_tourEndingDate()!=_items[index].get_tourEndingDate();
        
        if(differentTourID)
            continue;
        if(differntTourPrice)
            continue;
        if(differentIsTourInternational)
            continue;
        
        if(differentTourOrganiser)
            continue;
        if(differentTourDestination)
            continue;
        if(differentStartingDate)
            continue;
        if(differentEndingDate)
            continue;

        return _items[index];
    }
    
    return Tour{};
}
