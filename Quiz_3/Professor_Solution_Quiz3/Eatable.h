#ifndef Eatable_h
#define Eatable_h

#include <string>
using namespace std;

class Eatable {
    
private:
    string _name;
    
public:
    Eatable( string name );
    string get_name() const;
    virtual operator string() const = 0;
};

#endif 
