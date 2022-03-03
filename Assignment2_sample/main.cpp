#include <iostream>
#include "Bicycle.h"
#include "Inventory.h"

using namespace std;

// outputs abstraction object properties to the console window
void show(Bicycle item)
{
    cout << item.get_id() << " "
         << "'" << item.get_type() << "' "
         << item.get_price() << " "
         << endl;
}

// solution entry function
int main()
{
    Inventory inv;

    inv.init();

    // adds several different abstraction objects to the inventory
    inv.add_item(1, "BMX", 499.99);
    inv.add_item(2, "MTB", 549.99);

    Bicycle qry;
    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    qry.init(2, "", 0.0);
    show(inv.find_item(qry));

    // tests with different query values
    qry.init(0, "BMX", 0.0);
    show(inv.find_item(qry));

    // tests for nonmatching object
    qry.init(0, "Beach", 0.0);
    show(inv.find_item(qry));

    return 0;
}
