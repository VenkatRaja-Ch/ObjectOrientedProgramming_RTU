// Assignment: 5

#include "Tour.h"
#include "Inventory.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <memory>

using namespace std;

  
// outputs abstraction object properties to the console window
void show(const Tour & item )
{
    
    cout << "========================================" << endl;
    cout << endl;
    cout << "Tour id: " << item.get_tourID() << endl;
    cout << "Tour Organiser: " << item.get_tourOrganiser() << endl;
    
    auto is_pointer_pointing { item.get_tourSpec() };
    
    // checking whether the smart pointer is pointing to an objec or not.
    if( is_pointer_pointing )
    {
        cout << "Tour Destination: " << is_pointer_pointing -> get_tourDestination() << endl;
        cout << "Tour Startind date: " << is_pointer_pointing -> get_tourStartingDate() << endl;
        cout << "Tour Ending date: " << is_pointer_pointing -> get_tourEndingDate() << endl;
        cout << "Tour is international: " << is_pointer_pointing -> get_isTourInternational_as_String() << endl;
        cout << "Tour Price: " << is_pointer_pointing -> get_tourPrice() << endl;
        cout << "Tour Duration: " << is_pointer_pointing -> get_tourDuration() << " Days" << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
}

// Assignment:03 -     Task: 08
Tour max_pricedTour( const Inventory & inv )
{
    size_t inventorySize = inv.get_count();
    double maxPrice = ( (inv.get_item(0)).get_tourSpec()->get_tourPrice() );
    double currentPricedElement, maxPricedElementIndex = 0;
    
    for (int index=0; index<inventorySize; index++) {
        
        currentPricedElement = ( inv.get_item(index).get_tourSpec()->get_tourPrice() );
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
        currentTourPrice = inv.get_item(index).get_tourSpec()->get_tourPrice();
        sumOfAllTourPrice += currentTourPrice;
    }
    
    averageTourPrice = ( sumOfAllTourPrice / inventorySize );
    
    return averageTourPrice;
}


// solution entry function
int main ()
{
    Inventory inv;
    
    // TourSpec object for Internation Trip of Jorden
    
    auto jordenTour{ make_shared<TourSpec>(TourSpec::IsInternational::YES, 1799.99, "Jorden", "15.05.2022", "27.05.2022",12) };
    
    // add several different abstraction objects to the inventory
    inv.add_item(1, "Expedia", make_shared <TourSpec> (TourSpec::IsInternational::YES,2999.99,"New York","20.02.2022","02.03.2022",10));
    assert(1 == inv.get_count());
    
    inv.add_item(2, "Baltic Travel", make_shared <TourSpec> (TourSpec::IsInternational::NO,199.99,"Riga","20.09.2022","25.09.2022",5));
    assert(2 == inv.get_count());

    inv.add_item(3, "Go Travel", make_shared  <TourSpec> (TourSpec::IsInternational::YES,2000.99,"India","20.03.2023","01.04.2023", 12));
    assert(3 == inv.get_count());

    // adding the TourSpec object directly
    inv.add_item(4, "Expedia", jordenTour);
    assert(4 == inv.get_count());
    
    // uncomment the code to check the working of the task
    // trying to add a existing item
//    inv.add_item(4, "Expedia", "Jorden", 1799.00, "15.05.2022", "27.05.2022", Tour::IsInternational::YES);
    
    
    // Assignment:4 - Task 4
    // provides querying values (some can be default (eg, "", 0) to denote unset criteria)
    Tour qry0(3, "", make_shared <TourSpec> (TourSpec::IsInternational::YES,0.0,"","","",0));
    show( inv.find_item( qry0 ));
    
    // tests with different query values
    Tour qry1(0, "Expedia", make_shared <TourSpec> (TourSpec::IsInternational::YES,0.0,"","","",0));
    show(inv.find_item( qry1 ));
    
    
    // tests for nonmatching object
    Tour qry2(0, "RandomOrganisation", make_shared <TourSpec> (TourSpec::IsInternational::ANY,0.0,"Unkown","-.-.-","-.-.-",0));
    show(inv.find_item( qry2 ));
    
    
    // Most Expensive Tour Package ( to test function max_pricedTour() )
    cout << "\n\nMost Expensive Tour Package: \n";
    show( max_pricedTour(inv) );
    constexpr double epsil { 0.005 };
    assert( epsil < abs((2999.99*epsil) - max_pricedTour(inv).get_tourSpec()->get_tourPrice()));
    
    // Average price for Tour Packages ( to test function avg_priceOfTour() )
    assert( epsil < abs((1750.23*epsil) - avg_priceOfTour(inv) ));
    cout << "Average Tour Price: " << avg_priceOfTour(inv) << endl;
    
    
    cout << "\n\nOverloading Part:" << endl;
    show(inv.find_item(*jordenTour));
    
    
    cout << "\n\nAdding another Jorden Tour with different Organiser" << endl;
    inv.add_item(5, "Across The Globe Travels", jordenTour);
    cout << "<-- With default value in Tour object -->" << endl;
    Tour qry3(0, "", jordenTour);
    show(inv.find_item(qry3));
    show(inv.find_item(*jordenTour));
    
    cout << "<-- Without default value in Tour object -->" << endl;
    Tour qry4(5, "", jordenTour);
    show(inv.find_item(qry4));
    show(inv.find_item(*jordenTour));
    
    cout << "\n\nAdding another TourSpec:" << endl;
    auto budapest_tour {make_shared <TourSpec> (TourSpec::IsInternational::YES, 1359.99, "Budapest", "22.03.2021", "27.03.2021", 5) };
    inv.add_item(6, "Expedia", budapest_tour);
    assert( 6 == inv.get_count());
    inv.add_item(7, "Go Travels", budapest_tour);
    assert( 7 == inv.get_count());
    show(inv.find_item(*budapest_tour));
    Tour qry5(7,"",budapest_tour);
    Tour qry6(0,"",budapest_tour);
    show(inv.find_item(qry5));
    show(inv.find_item(qry6));
    
    
    return 0;
}
