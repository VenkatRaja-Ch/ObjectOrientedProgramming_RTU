#include "Eatable.h"
#include <exception>

Eatable::Eatable ( string name ) {
    
    if( !name.length() )
        throw domain_error( "Name cannot be empty" );
    _name = name;
}

string Eatable::get_name() const { return _name; }

Eatable::operator string() const {
    return "Name: " + _name;
}
