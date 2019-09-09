// ====================================================
//Your name: Thomas Gorney
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h"

//PURPOSE: Constructor to initialize
llist::llist() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
}

//PURPOSE: Destructor
llist::~llist() {
	el_t temp;
	while(!isEmpty())
		{deleteFront(temp);}
}

//PURPOSE: Check to see if the list is empty
bool llist::isEmpty() {
	if(Front == NULL && Rear == NULL && Count == 0)	//Checks if the front, rear and the count are all zero
		{return true;} else							//returns true if they are
		{return false;}
}

//PURPOSE: Displays all the elements in the list surrounded by brackets
//			if the list is empty then it will display empty, otherwise it
//			goes through the list displaying each element one at a time.
void llist::displayAll() {
	if (isEmpty())							//Special Case: First check if list is empty
		{cout << "[ empty ]" << endl;}
	else {									//Otherwise go through the list and output each element
		Node *pointer = Front;
		cout <<"[ ";
		while (pointer != NULL) {			//Goes through the list as long as the pointer is not empty

			cout << pointer->Elem << " ";	//**
			pointer = pointer->Next;
		}
		cout << "]" << endl;

		}
}

//PURPOSE: Adds elements to the front of the list. First checks if it is the first element.
//			If it is then it adds it to the front. Otherwise it adds elements to the rear.
//PARAMETER: pass in the element NewNum to be added to the rear of the list.
void llist::addRear(el_t NewNum) {
	if (Front == NULL){			//Special Case: Checks if the front is empty, if it is add to first spot on list
		Front = new Node;
		Rear = Front;			//Front and rear point to new Node
		Rear->Elem = NewNum;	//Put NewNum in the Elem field of new node
		Rear->Next = NULL;
		Count++;
	}
	else{						//Regular Case: Otherwise it will add elements to the rear of the list
		Rear->Next = new Node;
		Rear = Rear->Next;
		Rear->Elem = NewNum;	//Put NewNum in the Elem field of new node
		Rear->Next = NULL;
		Count++;
	}
}
//PURPOSE: Adds elements to the front of the list. First checks to see if it is the front of the list.
//			If it is the front then it adds to the first slot. Otherwise it adds it to the front and links
//			the node to the next element.
//PARAMETER: Passes in element NewNum to be added to the front of the list.
void llist::addFront(el_t NewNum) {
	if (Front == NULL) {		//Special Case: Checks if the front is empty, if it is add to first spot on list
		Front = new Node;
		Rear = Front;			//Front and rear point to new Node
		Front->Elem = NewNum;	//Put NewNum in the Elem field of new node
		Front->Next = NULL;

		Count++;
	    }
	else {						//Regular Case: Otherwise it will add elements to the rear of the list
		Node *pointer;
		pointer = new Node;
		pointer->Next = Front;
		Front = pointer;
		Front->Elem = NewNum;	//Put NewNum in the Elem field of new node
		Count++;
	}

}

//PURPOSE: Deletes an element from the front of the list. First checks to see if the list is empty,
//			if it is empty then it will throw an Underflow exception. Then checks to see if it is it is
//			the only element in the list if Count == 1, if it is then it deletes the only element and sets
//			rear and front back to NULL. Otherwise it will delete the first element of the list and point the
//			pointer to the next node while reducing the count.
//PARAMETER: Passes in the element OldNum, which is the number to be deleted from the front of the list.
void llist::deleteFront(el_t& OldNum) {
	if(isEmpty()){					//Error Case: Check to see if list is empty
		throw Underflow();
	}else if(Count == 1){			//Special Case: Check to see if we are at position 1 in list
		OldNum = Front -> Elem;
		delete Front;				//deletes front
		Front = NULL;				//Set front and rear back to NULL since it is now empty again
		Rear = NULL;
		Count --;
	}else{							//Regular Case: Otherwise we delete the element at the front and update the pointer to point to next element
		OldNum = Front->Elem;		//Give back front node through OldNum
		Node *Second;
		Second = Front->Next;
		delete Front;				//Remove front node
		Front = Second;
		Count--;
	}
}

//PURPOSE: Deletes an element from the rear of the list. First checks to see if the list is empty,
//			if it is empty then it will throw an Underflow exception. Then checks to see if it is it is
//			the only element in the list if Count == 1, if it is then it deletes the only element and sets
//			rear and front back to NULL. Otherwise it will delete the rear element of the list, sets the next
//			eleent to NULL and reduces the count.
//PARAMETER:Passes in OldNum which is the element to be deleted from the rear.
void llist::deleteRear(el_t& OldNum) {
	if(isEmpty())						//Error Case: Check to see if list is empty
		{throw Underflow();}
	else if(Count == 1){				//Special Case: Check to see if we are at position 1 in list
		OldNum = Rear->Elem;
		delete Rear;					//deletes rear
		Front = NULL;					//Set front and rear back to NULL since it is now empty again
		Rear = NULL;
		Count--;
	}else {								//Regular Case: Otherwise we delete the element at the front and update the pointer to point to next element
		Node *pointer = Front;
		while(pointer->Next != Rear)	//Goes through the list until we are at the rear
			{pointer = pointer->Next;}
		OldNum = Rear->Elem;			//OldNum is now set to the rear element
		delete Rear;
		Rear = pointer;					//Delete rear and point next to NULL
		Rear->Next = NULL;
		Count--;
	}
}

//PURPOSE: Deletes the element that is specified. First checks if it is in bounds, if not then throws
//			OutOfRange exception. Then checks if the count is equivalent to I, if it is then it deletes the rear,
//			or if it is the first element then it deletes the front element. Otherwise it deletes the the specified element
//			and replaces it with another.
//PARAMETER: I is the element that is to be deleted, and OldNum is the new number being placed in that spot.
void llist::deleteIth(int I, el_t& OldNum) {
	if(I > Count || I < 1)				//Error Case: Check if it is in range
		{throw OutOfRange();}
	else if(I == 1)					//Special Case: Check if we are at the rear
		{deleteFront(OldNum);}
	else if(I == Count)						//Special Case: Check if we are at the front
		{deleteRear(OldNum);}
	else {								//Regular Case: Delete the Ith node						//variable to go through the list
		Node *pointer = Front;
		Node *otherP = Front->Next;
		for(int c = 1; c <= I-1; c++){				//Goes through list until we are at the designated I
			pointer= pointer->Next;
			otherP = otherP->Next;
		}
		pointer->Next = otherP->Next;	//Sets otherP's next to pointer's next
		OldNum = otherP->Elem;			//Sets otherP's element to the number to be deleted
		delete otherP;					//Deletes the number
		Count--;
	}
}
//PURPOSE: Inserts an element into the list at the designated spot. First check if the list is out of range,
//			if it is then thrown an OutOfRange exception. Then check if we are the first element of the list,
//			if so then add it to the front. Check if it is the rear of the list, if so then add it to the rear.
//			Otherwise then we insert into the specified spot.
//PARAMETER: Passes in I, the position to insert into, and then the newNum to be inserted.
void llist::insertIth(int I, el_t newNum) {
	if (I > Count+1 || I < 1)			//Error Case: Check if it is in range
		{throw OutOfRange();}
	else if (I == 1)					//Special Case: Check if we are at the front
		{addFront(newNum);}
	else if (I == Count+1)				//Special Case: Check if we are at the rear
		{addRear(newNum);}
	else {								//Regular Case: If not at front or rear then insert						//Variable to go through list
		Node *pointer = Front;
		for(int c = 1; c <= I-1;c++){				//Goes through list until we are at the designated I
			pointer = pointer->Next;
		}
		Node *otherP = pointer->Next;
		pointer->Next = new Node;		//Makes a new node where we need it
		pointer->Next->Next = otherP;	//Sets this nodes next to the temporary otherP node
		pointer->Next->Elem = newNum;	//Puts newNum in that node
		Count++;
	}
}
//PURPOSE: Construct a new list from a copied list. Copies a list and adds each element to the rear
//PARAMETER: Passes in by reference another list Original, to be copied.
llist::llist(const llist& Original) {
	Front = NULL;
	Rear = NULL;
	Count = 0;
	Node *pointer;
	pointer = Original.Front;
	while(pointer != NULL){				//Goes through the list
		this->addRear(pointer->Elem);	//Adds the elements from
		pointer = pointer->Next;
	}
}

//PURPOSE: Overload the assignment operator in order to allow lists to be copied.
//PARAMETER: Passes in by reference the list we want to be able to copy from.
llist& llist::operator=(const llist& OtherOne) {
	if(&OtherOne != this){
		el_t elem;
		while(!this->isEmpty())
			{this->deleteRear(elem);}
		Node *pointer;
		pointer = OtherOne.Front;			//Sets OtherOnes front to pointer temp node
		while(pointer != NULL){				//Goes through the list
			this->addRear(pointer->Elem);	//Adds each element from OtherOne to this new list
			pointer = pointer->Next;
		}
	}
	return *this;							// return the result unconditionally.
}

