// Assignment: 5
#include "TourSpec.h"


bool TourSpec::matches(const TourSpec &otherSpec) const
{
    // self check whether the current object and the passed object matches
    if( this == &otherSpec )
        return true;
    
    // for string type property
    bool differentIsTourInternational = ( (otherSpec.get_isTourInternational() != TourSpec::IsInternational::ANY)
        &&
        otherSpec.get_isTourInternational() != get_isTourInternational());
    
    constexpr double epsil{ 0.005 };
    bool differentTourPrice = ( (otherSpec.get_tourPrice()!=0.0) && (epsil < abs(otherSpec.get_tourPrice() - get_tourPrice())) );
    
    bool differentTourDestination = otherSpec.get_tourDestination()!="" && otherSpec.get_tourDestination()!=get_tourDestination();
    
    bool differentStartingDate = otherSpec.get_tourStartingDate()!="" && otherSpec.get_tourStartingDate()!=get_tourStartingDate();
    
    bool differentEndingDate = otherSpec.get_tourEndingDate()!="" && otherSpec.get_tourEndingDate()!=get_tourEndingDate();
    
    bool differentTourDuration = otherSpec.get_tourDuration()!=0 &&   otherSpec.get_tourDuration()!=get_tourDuration();

    if(differentTourPrice)
        return false;
    if(differentIsTourInternational)
        return false;
    if(differentIsTourInternational)
        return false;
    if(differentTourDestination)
        return false;
    if(differentStartingDate)
        return false;
    if(differentEndingDate)
        return false;
    if(differentTourDuration)
        return false;
    
    return true;
}
