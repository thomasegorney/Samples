//=================================================
// Name: Thomas Gorney
// File: Header File slist.h
//=================================================

#include "llist.h"

class slist: public llist{
public:

//PURPOSE: Constructs the llist
 slist();

 //PURPOSE: Search through the list to see if any node contains key.
 //PARAMETER: Passes in an element that is to be searched for.
el_t search(el_t);

//PURPOSE: Go to the Ith node and replace the element there with Elem.
//PARAMETER: Passes in element to be replaced and the location of the number to be replaced.
void replace(el_t,  int);

//PURPOSE: Overload the == operator in order to make slists comparable.
//PARAMETER: Passes in the reference of the list we want to compare to.
bool operator==(const slist&);
// checks to see of the two lists look the same
    

};
