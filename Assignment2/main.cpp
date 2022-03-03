#include "Tour.h"
#include "Inventory.h"
#include <iostream>

using namespace std;


// outputs abstraction object properties to the console window
void show( Tour item )
{
    cout << "========================================" << endl;
    cout << endl;
    cout << "Tour id: " << item.get_tourID() << endl;
    cout << "Tour Organiser: " << item.get_tourOrganiser() << endl;
    cout << "Tour Destination: " << item.get_tourDestination() << endl;
    cout << "Tour Startind date: " << item.get_tourStartingDate() << endl;
    cout << "Tour Ending date: " << item.get_tourEndingDate() << endl;
    cout << "Tour is international: " << (item.get_isTourInternational() ? "Yes" : "No") << endl;
    cout << "Tour Price: " << item.get_tourPrice() << endl;
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
}

// solution entry function
int main ()
{
    Inventory inv;
    
    inv.init();
    
    // add several different abstraction objects to the inventory
    inv.add_item(1, "Expedia", "New York", 2999.00, "20.02.2022", "02.03.2022", true);
    assert(1 == inv.get_count());
    
    inv.add_item(2, "Baltic Travel", "Riga", 199.00, "20.09.2022", "25.09.2022", false);
    assert(2 == inv.get_count());
    
    inv.add_item(3, "Go Travel", "India", 2000.00, "20.03.2023", "01.04.2023", true);
    assert(3 == inv.get_count());
    
    inv.add_item(4, "Expedia", "Jorden", 1799.00, "15.05.2022", "27.05.2022", true);
    assert(4 == inv.get_count());
    
    Tour qry;
    // provides querying values (some can be default (eg, "", 0) to denote unset criteria)
    qry.init(3, "", "", 0.00, "", "", false);
    show( inv.find_item(qry));
    
    // tests with different query values
    qry.init(0, "Expedia", "", 0.00, "", "", false);
    show(inv.find_item(qry));
    
    // tests for nonmatching object
    qry.init(0, "RandomOrganisation", "Unkown", 0.00, "-.-.-", "-.-.-", true);
    show(inv.find_item(qry));
    
    return 0;
}
