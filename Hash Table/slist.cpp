// =======================================================
// Your name: Thomas Gorney
// Compiler:  g++
// File type: source file slist.cpp
//=======================================================

#include <iostream>
#include "slist.h"
using namespace std;

//PURPOSE: Constructs the llist
  slist::slist(){}	// constructor which is the same as the llist one

  //PURPOSE: Search through the list to see if any node contains key.
  //PARAMETER: Passes in an element that is to be searched for.
  el_t slist::search(el_t key){		//Key to be searched for
	  int position = 1;				//Set position to the first one
	  Node *pointer = Front;		//Sets the pointer to be the front
	  while(pointer != NULL){		//Loop to make sure we are still in the list
		  if (pointer->Elem == key)	//Check if an element is equal to the key
		  	  {return key;}	//if it is return its position
		  pointer = pointer->Next;
		  position++;
	  }
	  el_t empty(0, " ");
		return empty;
	  }

  //PURPOSE: Go to the Ith node and replace the element there with Elem.
  //PARAMETER: Passes in element to be replaced and the location of the number to be replaced.
	void slist::replace(el_t rep,  int I){
		if( I > Count || I < 1)					//Check if we are still in bounds
			{cout << "error" << endl;}			//should throw OutOfRange(), but did not want program to exit
		else{
			int j = 1;							//Sets j so we can use it as a counter to traverse list
			Node *pointer = Front;
			while(j < I)						//Loop to traverse list
				{pointer = pointer->Next;j++;}
			pointer->Elem = rep;				//Replace Elem with the passed in variable once I is reached
		}

	}

	//PURPOSE: Overload the == operator in order to make slists comparable.
	//PARAMETER: Passes in the reference of the list we want to compare to.
    bool slist::operator==(const slist& OtherOne){
    	if(this->Count == OtherOne.Count){						//Check if the lists are the same size
    		Node *thisPointer = this->Front;					//Sets both lists to the front
    		Node *otherPointer = OtherOne.Front;
    		while(thisPointer != NULL && otherPointer != NULL){	//Loop to make sure we are still in both lists
    			if(thisPointer->Elem == otherPointer->Elem)		//Check if the elements are not equal **
    				{
    				return true;
    				}else{
    					thisPointer = thisPointer->Next;
						otherPointer = otherPointer->Next;
    					return false;
    				}								//if they are not return false (they are not equal)

    		} 	//end while(thisPointer != NULL && otherPointer != NULL){
    		return true;										//Otherwise they the same
    	}		//end if(this->Count == OtherOne.Count){
    	else
    		{return false;}										//If counts not equal to each other then lists not equal
    }




