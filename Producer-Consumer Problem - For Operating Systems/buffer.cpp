/*
 * buffer.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: tommy
 */


#include "buffer.h"
#include <iostream>
using namespace std;
/* the buffer */
buffer_item buffer[BUFFER_SIZE];

int buffCount = 0;
int first = 0;
int last = 0;

int insert_item(buffer_item item){
	//insert item into buffer
	if(buffCount != BUFFER_SIZE){
		buffer[last] = item;
		last = (last + 1) % BUFFER_SIZE;
		buffCount++;
		return 0;	//return 0 if successful
	}
	return -1;		//return -1 indicating error condition

}

int remove_item(buffer_item *item){
	//remove an object from buffer
	if(buffCount != 0){
		*item = buffer[first];	// placing it in item
		first = (first + 1) % BUFFER_SIZE;
		buffCount--;
		return 0;	// return 0 if successful
	}
	return -1;		// return -1 indicating error condition
}

//Displays the buffer
void DisplayBuffer(){
	if(buffCount == 0){
			cout << "Empty Buffer" << endl;
		}else{
			cout << "The current content of the buffer is [ ";
			for(int i = first; i < last; i++){
				cout << buffer[i] << " ";
			}
			cout << "]" << endl;
		}






}
