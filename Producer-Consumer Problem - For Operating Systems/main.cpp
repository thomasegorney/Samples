//============================================================================
// Name        : OW.cpp
// Author      : Thomas Gorney
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "buffer.h"
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

void DisplayBuffer();
int insert_item(buffer_item item);
int remove_item(buffer_item *item);
pthread_mutex_t mutex;
sem_t semT;		//Top
sem_t semB;		//Bottom


void *producer(void *param){
	buffer_item item;
	while(true){
		sleep(rand() % 5);	  //Sleep for a random period of time
		item = rand() % 100 + 1; //Generate a random number
		sem_wait(&semB);
		pthread_mutex_lock(&mutex);
		if(insert_item(item)){
			cout << "Report error condition PRODUCER" << endl;
	}else{
		cout << "Producer produced " << item << " ";
					DisplayBuffer();

		}
		pthread_mutex_unlock(&mutex);
		sem_post(&semT);
	}

}

void *consumer(void *param){
	buffer_item item;
	while(true){
		sleep(rand() % 5);	  //Sleep for a random period of time
		sem_wait(&semT);
		pthread_mutex_lock(&mutex);
		if(remove_item(&item)){
			cout << "Report error condition CONSUMER" << endl;
		}else{
			cout << "Consumer consumed " << item << " ";
			DisplayBuffer();
		}
		pthread_mutex_unlock(&mutex);
		sem_post(&semB);
	}
}


int main(int argc, char*argv[]) {

// 1. Get command line arguments arv[1], argv[2], argv[3]
	int sleepArg   =  	atoi(argv[1]);	//How long the main thread sleep before terminating
	int produceArg =    atoi(argv[2]);	//The number of producer threads
	int consumeArg = 	atoi(argv[3]);	//The number of consumer threads

 //2. Initialize buffer
	pthread_t produceThreads[produceArg];
	pthread_t consumeThreads[consumeArg];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&semB, 0, BUFFER_SIZE);
	sem_init(&semT, 0, 0);
 //3. Create producer threads
	for(int i = 0; i < produceArg; i++){
		pthread_create(&produceThreads[i], NULL, producer, NULL);
	}
 //4. Create consumer threads
	for(int i = 0; i < consumeArg; i++){
		pthread_create(&consumeThreads[i], NULL, consumer, NULL);
	}
 //5. Sleep
	sleep(sleepArg);
 //6. Exit
	exit(0);
}
