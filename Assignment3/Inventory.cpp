// Assignment: 3

#include "Inventory.h"

// The parameters must match with the class declaration
void Inventory::add_item( int id, string organiser, string destination, double price, string startingDate, string endingDate, Tour::IsInternational isTourInternational )
{
    
    if (_count < Inventory::MAX_SIZE)
    {

        Tour new_item;
        new_item.init( id, organiser, destination, price, startingDate,endingDate, isTourInternational );
        
        
        // Task: 10
        bool itemNotFound = (find_item(new_item).get_tourID() != id);
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
        
        
        constexpr double epsil{ 0.005 };
        //bool differentTourPrice = query.get_tourPrice()!=0.0 && query.get_tourPrice()!=_items[index].get_tourPrice();
        bool differentTourPrice = ( (query.get_tourPrice()!=0.0) && (epsil < abs(query.get_tourPrice() - _items[index].get_tourPrice())) );
        
        
        // for string type property
        bool differentIsTourInternational = ( (query.get_isTourInternational() != Tour::IsInternational::ANY) && (query.get_isTourInternational() != _items[index].get_isTourInternational()) );
       
        bool differentTourOrganiser = query.get_tourOrganiser()!="" && query.get_tourOrganiser()!=_items[index].get_tourOrganiser();
        
        bool differentTourDestination = query.get_tourDestination()!="" && query.get_tourDestination()!=_items[index].get_tourDestination();
        
        bool differentStartingDate = query.get_tourStartingDate()!="" && query.get_tourStartingDate()!=_items[index].get_tourStartingDate();
        
        bool differentEndingDate = query.get_tourEndingDate()!="" && query.get_tourEndingDate()!=_items[index].get_tourEndingDate();
        
        
        if(differentTourID)
            continue;
        if(differentTourPrice)
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
