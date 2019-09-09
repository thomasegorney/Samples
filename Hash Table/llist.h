// =======================================================
// Your name: Thomas Gorney
// Compiler:  g++
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
#include "elem.h"

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
 protected:
	Node *Front;       // pointer to the front node
	Node *Rear;        // pointer to the rear node
	int  Count;        // counter for the number of nodes
 private:


 public:

  // Exception handling classes
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes

  //PURPOSE: Check to see if the list is empty
  bool isEmpty();

  //PURPOSE: Displays all the elements in the list surrounded by brackets
  //			if the list is empty then it will display empty, otherwise it
  //			goes through the list displaying each element one at a time.
  void displayAll();

  //PURPOSE: Adds elements to the front of the list. First checks to see if it is the front of the list.
  //			If it is the front then it adds to the first slot. Otherwise it adds it to the front and links
  //			the node to the next element.
  //PARAMETER: Passes in element NewNum to be added to the front of the list.
  void addFront(el_t);

  //PURPOSE: Adds elements to the rear of the list. First checks if it is the first element.
  //			If it is then it adds it to the front. Otherwise it adds elements to the rear.
  //PARAMETER: pass in the element NewNum to be added to the rear of the list.
  void addRear(el_t);

  //PURPOSE: Deletes an element from the front of the list. First checks to see if the list is empty,
  //			if it is empty then it will throw an Underflow exception. Then checks to see if it is it is
  //			the only element in the list if Count == 1, if it is then it deletes the only element and sets
  //			rear and front back to NULL. Otherwise it will delete the first element of the list and point the
  //			pointer to the next node while reducing the count.
  //PARAMETER: Passes in the element OldNum, which is the number to be deleted from the front of the list.
  void deleteFront(el_t&);

  //PURPOSE: Deletes an element from the rear of the list. First checks to see if the list is empty,
  //			if it is empty then it will throw an Underflow exception. Then checks to see if it is it is
  //			the only element in the list if Count == 1, if it is then it deletes the only element and sets
  //			rear and front back to NULL. Otherwise it will delete the rear element of the list, sets the next
  //			eleent to NULL and reduces the count.
  //PARAMETER:Passes in OldNum which is the element to be deleted from the rear.
  void deleteRear(el_t&);

  //PURPOSE: Deletes the element that is specified. First checks if it is in bounds, if not then throws
  //			OutOfRange exception. Then checks if the count is equivalent to I, if it is then it deletes the rear,
  //			or if it is the first element then it deletes the front element. Otherwise it deletes the the specified element
  //			and replaces it with another.
  //PARAMETER: I is the element that is to be deleted, and OldNum is the new number being placed in that spot.
  void deleteIth(int, el_t&);

  //PURPOSE: Inserts an element into the list at the designated spot. First check if the list is out of range,
  //			if it is then thrown an OutOfRange exception. Then check if we are the first element of the list,
  //			if so then add it to the front. Check if it is the rear of the list, if so then add it to the rear.
  //			Otherwise then we insert into the specified spot.
  //PARAMETER: Passes in I, the position to insert into, and then the newNum to be inserted.
  void insertIth(int, el_t);

  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);

  //Overloading of =
  llist& operator=(const llist&);

};
