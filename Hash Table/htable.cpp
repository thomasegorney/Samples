// ============================================
// HW#: HW8 Hash Table
// Name: Thomas Gorney
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
 {}

htable::~htable()
{}

// a simple hash function that uses % TSIZE
int htable::hash(int key)
{
	int slot = (key % TSIZE);
	return slot;
}

// adds the element to the table and returns slot#
int htable::add(el_t element)
{
   int slot = hash(element.key);
   table[slot].addRear(element);
   return slot;
}

// finds element using the skey and returns the element itself
el_t htable::find(int skey)
{
   int slot = hash(skey);
   el_t slement;  				// this is the element to look for in slist
   slement.key = skey;			// initialize it with skey
   table[slot].search(slement);	// call slist's search for selement which returns an element
   return slement;
   if(slement.key > 0){
	   return slement;
   }else{
	   cout << "Nothing found." << endl;
   }
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < 37; i++)
    { cout << i << ":" ;
    	table[i].displayAll();	// call slist's displayAll+
    }
}
