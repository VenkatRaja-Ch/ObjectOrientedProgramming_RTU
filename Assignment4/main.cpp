// Assignment: 4

#include "Tour.h"
#include "Inventory.h"
#include <iostream>
#include <cassert>

using namespace std;

  
// outputs abstraction object properties to the console window
void show(const Tour & item )
{
    
    cout << "========================================" << endl;
    cout << endl;
    cout << "Tour id: " << item.get_tourID() << endl;
    cout << "Tour Organiser: " << item.get_tourOrganiser() << endl;
    cout << "Tour Destination: " << item.get_tourDestination() << endl;
    cout << "Tour Startind date: " << item.get_tourStartingDate() << endl;
    cout << "Tour Ending date: " << item.get_tourEndingDate() << endl;
    
    
    cout << "Tour is international: " << item.get_tourSpec().get_isTourInternational_as_String () << endl;
    
    
    cout << "Tour Price: " << item.get_tourPrice() << endl;
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
}

// Assignment:03 -     Task: 08
Tour max_pricedTour( const Inventory & inv )
{
    
    size_t inventorySize = inv.get_count();
    double maxPrice = ( (inv.get_item(0)).get_tourPrice() );
    double currentPricedElement, maxPricedElementIndex = 0;
    
    for (int index=0; index<inventorySize; index++) {
        
        currentPricedElement = ( inv.get_item(index).get_tourPrice() );
        if( currentPricedElement >= maxPrice ){
            
            maxPrice = currentPricedElement;    // storing the maximum price
            maxPricedElementIndex = index;      // storing index position at which maximum priced element is placed
        }
    }
    
    
    return inv.get_item(maxPricedElementIndex);
}


// Assignment:03 - Task: 09
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
    
    
    TourSpec tourSpec1(TourSpec::IsInternational::YES);
    
    
    // add several different abstraction objects to the inventory
    inv.add_item(1, "Expedia", "New York", 2999.00, "20.02.2022", "02.03.2022", tourSpec1);
    assert(1 == inv.get_count());

    inv.add_item(2, "Baltic Travel", "Riga", 199.00, "20.09.2022", "25.09.2022", TourSpec(TourSpec::IsInternational::NO));
    assert(2 == inv.get_count());
    
    inv.add_item(3, "Go Travel", "India", 2000.00, "20.03.2023", "01.04.2023", tourSpec1);
    assert(3 == inv.get_count());
    
    inv.add_item(4, "Expedia", "Jorden", 1799.00, "15.05.2022", "27.05.2022", tourSpec1);
    assert(4 == inv.get_count());
    
    
    
    // Assignment:03 - Task 10: When same file is add, then it terminates the program since the item is already added in the datatbase.
    // uncomment the code to check the working of the task
    // trying to add a existing item
//    inv.add_item(4, "Expedia", "Jorden", 1799.00, "15.05.2022", "27.05.2022", Tour::IsInternational::YES);
//    assert(5 == inv.get_count());
    
    
    // Assignment:4 - Task 4
    // provides querying values (some can be default (eg, "", 0) to denote unset criteria)
    Tour qry0(3, "", "", 0.00, "", "", TourSpec(TourSpec::IsInternational::YES));
    show( inv.find_item( qry0 ));
    
    // tests with different query values
    Tour qry1(0, "Expedia", "", 0.00, "", "", TourSpec(TourSpec::IsInternational::YES));
    show(inv.find_item( qry1 ));
    
    
    // testing for overloading
    cout << "\n\nTesting for Fucntion Overloding\n";
    show(inv.find_item( TourSpec( TourSpec::IsInternational::YES )));
    
    
    // tests for nonmatching object
    Tour qry2(0, "RandomOrganisation", "Unkown", 0.00, "-.-.-", "-.-.-", TourSpec(TourSpec::IsInternational::ANY));
    show(inv.find_item( qry2 ));
    
    
    cout << "\n\nMost Expensive Tour Package: \n";
    show( max_pricedTour(inv) );
    const double epsil { 0.005 };
    assert( epsil < (5000 - max_pricedTour(inv).get_tourPrice()));
    
    cout << "Average Tour Price: " << avg_priceOfTour(inv) << endl;
    
    return 0;
}
