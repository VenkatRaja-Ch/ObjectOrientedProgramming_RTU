#ifndef Basket_h
#define Basket_h

#include "Eatable.h"

class Basket {
  
private:
    static const int MAX_SIZE{ 10 };
    Eatable * _items[ MAX_SIZE ];
    size_t _count{ 0 };
public:
    void put( Eatable * new_item );
    void show_contents() const;
};

#endif /* Basket_h */
