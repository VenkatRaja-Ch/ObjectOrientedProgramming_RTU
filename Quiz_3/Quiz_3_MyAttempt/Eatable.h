#ifndef Eatable_h
#define Eatable_h

#include <string>
using namespace std;

class Eatable {
  
public:
    Eatable( string name ) : _name ( name ){}
    string get_name() const;
    
private:
    const string _name;
};

#endif /* Eatable_h */
