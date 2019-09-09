//============================================
// HW#: HW8 hashing client
// Name: Thomas Gorney
// File type: client hw8client.cpp
//===========================================

#include <iostream>
using namespace std;
#include "htable.h"
int main()
{
	string name;
	htable table;
	int key;

	//Enter a name
	cout << "Enter a name(Type exit to escape): ";
	cin >> name;
	//Enter a key
	cout << "Enter key: ";
	cin >> key;

	//While the name entered is not exit, keep looping
	while(name != "exit"){
		el_t el(key, name);			//create a new el_t object with key and name
		table.add(el);				//add the object to the table
		cout << "Enter a name(Type exit to escape): ";
		cin >> name;
		if(name != "exit"){
			cout << "Enter key: ";
			cin >> key;
		}
	}
	table.displayTable();				//Display the table.

	//Search for a specific key
	cout << "Enter a key to search: ";
	cin >> key;							//input the key to be searched
	el_t search =  table.find(key);		//store the found key in search
	search.display();					//display the search data

 }
