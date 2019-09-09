#include <iostream>
#include <string>
using namespace std;

class el_t
{
 private:
  int key;
  string name;

 public:

  el_t();
  el_t(int, string);

  void display();
  bool operator==(el_t);
  friend ostream& operator<<(ostream& os, const el_t& elm);
  friend class htable;  // only htable knows about private items
};
