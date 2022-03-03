#include "Inventory.h"

// The parameters must match with the class declaration
void Inventory::add_item(int id, string type, double price)
{
    if (_count < Inventory::MAX_SIZE)
    {
        Bicycle new_item;
        new_item.init(id, type, price);
        _items[_count] = new_item;
        _count++;
    }
}

Bicycle Inventory::find_item(Bicycle query)
{
    for (size_t i = 0; i < _count; i++)
    {
        // for integer and boolean type property
        if (query.get_id() != 0
            && query.get_id() != _items[i].get_id())
            continue;
        if (query.get_price() != 0
            && query.get_price() != _items[i].get_price())
            continue;

        // for string type property
        if (query.get_type() != ""
            && query.get_type() != _items[i].get_type())
            continue;

        return _items[i];
    }

    return Bicycle{}; // return the 'default' object
}
