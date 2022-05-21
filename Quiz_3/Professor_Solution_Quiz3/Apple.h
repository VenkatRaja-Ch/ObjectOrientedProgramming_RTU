#ifndef Apple_h
#define Apple_h

#include "Eatable.h"
#include <string>
using namespace std;

class Apple : public Eatable {
  
private:
    string _sort;
public:
    Apple( string name, string sort );
    string get_sort() const;
    virtual operator string() const override;
};

#endif 
