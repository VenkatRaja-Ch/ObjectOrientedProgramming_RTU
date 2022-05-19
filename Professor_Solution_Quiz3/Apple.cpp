#include "Apple.h"

Apple::Apple( string name, string sort ) : Eatable{ name }{
    
    if( !sort.length() )
        throw domain_error( "Sort cannot be empty" );
    _sort = sort;
}

string Apple::get_sort() const { return _sort; }

Apple::operator string() const {
    return Eatable::operator string() + ", Sort: " + _sort;
}
