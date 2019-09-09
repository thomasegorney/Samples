#include "slist.h"

const int TSIZE = 37;

class htable
{
 private:
  slist table[TSIZE];   // each node is a key and name
  int hash(int);

 public:
  htable();
  ~htable();

  int add(el_t);  // adds an element to the table and returns slot#
  el_t find(int); // finds an element based on key and returns it
  void displayTable(); // displays the table with slot#s

};
