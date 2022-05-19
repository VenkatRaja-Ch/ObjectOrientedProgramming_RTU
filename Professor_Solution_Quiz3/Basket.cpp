#include "Basket.h"
#include <iostream>

void Basket::put( Eatable * new_item ){
    if( !new_item )
        throw invalid_argument( "Eatable must not be null" );
    
    if( MAX_SIZE == _count )
        throw domain_error( "Basket is full." );
    
    _items[ _count++ ] = new_item;
}

void Basket::show_contents() const {
    
    for( auto i{ 0U }; i<_count; i++ ) {
        cout << ( string )*_items[ i ] << endl;
    }
}
