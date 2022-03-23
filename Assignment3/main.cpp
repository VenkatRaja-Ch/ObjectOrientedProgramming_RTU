#include "Tour.h"
#include "Inventory.h"
#include <iostream>
#include <cassert>

using namespace std;

  
// outputs abstraction object properties to the console window
void show(const Tour & item )
{
    
    static const char* IS_TOUR_INTERNATIONAL_S[]{ "ANY", "YES", "NO" };
    
    cout << "========================================" << endl;
    cout << endl;
    cout << "Tour id: " << item.get_tourID() << endl;
    cout << "Tour Organiser: " << item.get_tourOrganiser() << endl;
    cout << "Tour Destination: " << item.get_tourDestination() << endl;
    cout << "Tour Startind date: " << item.get_tourStartingDate() << endl;
    cout << "Tour Ending date: " << item.get_tourEndingDate() << endl;
    
    
    cout << "Tour is international: " << IS_TOUR_INTERNATIONAL_S[(size_t)item.get_isTourInternational()] << endl;
    
    
    cout << "Tour Price: " << item.get_tourPrice() << endl;
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
}

// Task: 08
Tour max_pricedTour( const Inventory & inv )
{
    
    size_t inventorySize = inv.get_count();
    double maxPrice = ( (inv.get_item(0)).get_tourPrice() );
    double currentPricedElement, maxPricedElementIndex = 0;
    
    for (int index=0; index<inventorySize; index++) {
        
        currentPricedElement = ( inv.get_item(index).get_tourPrice() );
        if( currentPricedElement >= maxPrice ){
            
            maxPrice = currentPricedElement;
            maxPricedElementIndex = index;
        }
    }
    
    
    return inv.get_item(maxPricedElementIndex);
}


// Task: 09
double avg_priceOfTour( const Inventory & inv)
{
    size_t inventorySize = inv.get_count();
    double averageTourPrice, currentTourPrice, sumOfAllTourPrice = 0;
    
    for (int index=0; index<inventorySize; index++) {
        currentTourPrice = inv.get_item(index).get_tourPrice();
        sumOfAllTourPrice += currentTourPrice;
    }
    
    averageTourPrice = ( sumOfAllTourPrice / inventorySize );
    
    return averageTourPrice;
}


// solution entry function
int main ()
{
    Inventory inv;
    
    inv.init();
    
    // add several different abstraction objects to the inventory
    inv.add_item(1, "Expedia", "New York", 2999.00, "20.02.2022", "02.03.2022", Tour::IsInternational::YES);
    assert(1 == inv.get_count());
    
    inv.add_item(2, "Baltic Travel", "Riga", 199.00, "20.09.2022", "25.09.2022", Tour::IsInternational::NO);
    assert(2 == inv.get_count());
    
    inv.add_item(3, "Go Travel", "India", 2000.00, "20.03.2023", "01.04.2023", Tour::IsInternational::YES);
    assert(3 == inv.get_count());
    
    inv.add_item(4, "Expedia", "Jorden", 1799.00, "15.05.2022", "27.05.2022", Tour::IsInternational::YES);
    assert(4 == inv.get_count());
    
    Tour qry;
    // provides querying values (some can be default (eg, "", 0) to denote unset criteria)
    qry.init(3, "", "", 0.00, "", "", Tour::IsInternational::YES);
    show( inv.find_item(qry));
    
    // tests with different query values
    qry.init(0, "Expedia", "", 0.00, "", "", Tour::IsInternational::YES);
    show(inv.find_item(qry));
    
    // tests for nonmatching object
    qry.init(0, "RandomOrganisation", "Unkown", 0.00, "-.-.-", "-.-.-", Tour::IsInternational::ANY);
    show(inv.find_item(qry));
    
    
    // Task 8:
    cout << "\n\nTask: 08\nMost Expensive Tour Package: \n";
    show( max_pricedTour(inv) );
    
    // Task 9:
    cout << "\n\nTask: 09\n";
    cout << "Average Tour Price: " << avg_priceOfTour(inv) << endl;
    
    return 0;
}
