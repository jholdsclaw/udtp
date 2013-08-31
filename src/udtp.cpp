//============================================================================
// Name        : udtp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <semaphore.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <poll.h>

using namespace std;
struct data{
	int id;
	string name;
};

void* exampleThread(void* data){
	struct data *data_ptr = (struct data*)data;
	cout << data_ptr ->name << " " << data_ptr->id << endl;
	return NULL;
}

bool createThread(int counter){
	pthread_t t1;
	data pass_data;
	pass_data.id = counter;
	pass_data.name = "Thread";
	pthread_create(&t1, NULL, exampleThread, &pass_data);
	pthread_join(t1, NULL);
	return true;
}

int main(int argc, char* argv) {
	for(int i=0; i<1000; i++){
		createThread(i);
	}

	return 0;

}
