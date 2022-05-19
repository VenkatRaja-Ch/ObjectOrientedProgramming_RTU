#ifndef Apple_h
#define Apple_h

#include <string>
#include "Eatable.h"
using namespace std;

class Apple : public Eatable {
  
public:
    Apple( string name, string sort ): Eatable ( name ){
        _sort = sort; 
    }
    
    ~Apple(){}
    
    string get_sort() const;
    
private:
    const string _sort;
};

#endif
