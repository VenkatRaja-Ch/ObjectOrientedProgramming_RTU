// Assignment: 4

#include "Inventory.h"
#include <cmath>

// The parameters must match with the class declaration
void Inventory::add_item( unsigned id, const string & organiser, const TourSpec & spec)
{
    
    if (_count < Inventory::MAX_SIZE)
    {

        Tour new_item ( id, organiser, spec );
        Tour found = find_item(new_item);
        
        // Assignment:03 - Task: 10
        bool itemNotFound = (id != found.get_tourID()) && (spec.get_isTourInternational() != found.get_tourSpec().get_isTourInternational());
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
        bool differentTourPrice = ( (query.get_tourSpec().get_tourPrice()!=0.0) && (epsil < abs(query.get_tourSpec().get_tourPrice() - _items[index].get_tourSpec().get_tourPrice())) );
        
        
        // for string type property
        bool differentIsTourInternational = ( (query.get_tourSpec().get_isTourInternational() != TourSpec::IsInternational::ANY)
                                             && (query.get_tourSpec().get_isTourInternational() != _items[index].get_tourSpec().get_isTourInternational()));
       
        bool differentTourOrganiser = query.get_tourOrganiser()!="" && query.get_tourOrganiser()!=_items[index].get_tourOrganiser();
        
        bool differentTourDestination = query.get_tourSpec().get_tourDestination()!="" && query.get_tourSpec().get_tourDestination()!=_items[index].get_tourSpec().get_tourDestination();
        
        bool differentStartingDate = query.get_tourSpec().get_tourStartingDate()!="" && query.get_tourSpec().get_tourStartingDate()!=_items[index].get_tourSpec().get_tourStartingDate();
        
        bool differentEndingDate = query.get_tourSpec().get_tourEndingDate()!="" && query.get_tourSpec().get_tourEndingDate()!=_items[index].get_tourSpec().get_tourEndingDate();
        
        if(differentTourID)
            continue;
        if(differentTourPrice)
            continue;
        if(differentIsTourInternational)
            continue;

        if(differentTourOrganiser)
            continue;
        if(differentIsTourInternational)
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

// for function overloading part
Tour Inventory::find_item(const TourSpec & spec_query) const
{
    
    for(size_t index = 0; index < _count; index++)
    {
        
        // for string type property
        bool differentIsTourInternational = ( (spec_query.get_isTourInternational() != TourSpec::IsInternational::ANY)
                                             && spec_query.get_isTourInternational() != _items[index].get_tourSpec().get_isTourInternational());
        
        constexpr double epsil{ 0.005 };
        bool differentTourPrice = ( (spec_query.get_tourPrice()!=0.0) && (epsil < abs(spec_query.get_tourPrice() - _items[index].get_tourSpec().get_tourPrice())) );
        
        bool differentTourDestination = spec_query.get_tourDestination()!="" && spec_query.get_tourDestination()!=_items[index].get_tourSpec().get_tourDestination();
        
        bool differentStartingDate = spec_query.get_tourStartingDate()!="" && spec_query.get_tourStartingDate()!=_items[index].get_tourSpec().get_tourStartingDate();
        
        bool differentEndingDate = spec_query.get_tourEndingDate()!="" && spec_query.get_tourEndingDate()!=_items[index].get_tourSpec().get_tourEndingDate();
        

        if(differentTourPrice)
            continue;
        if(differentIsTourInternational)
            continue;
        if(differentIsTourInternational)
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
