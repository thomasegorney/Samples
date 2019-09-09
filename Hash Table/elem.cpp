#include "elem.h"

// regular constructor - blank element
el_t::el_t()
{
  key = 0;
  name = "";
}

// special constructor - initialized element
el_t::el_t(int akey, string aname)
{
  key = akey;
  name = aname;
}

// displays an element (parts with +)  
void el_t::display()
{
  cout << key << "+" << name;
}

// defines == for elements
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key)
  return true; else return false;

}

ostream& operator<<(ostream& os, const el_t& elm)
{
    os << elm.key << '+' << elm.name;

    return os;
}
