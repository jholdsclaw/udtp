//============================================================================
// Name        : UDP-based file transfer (UDTP)
// Author      : Lucky
// Version     : 0.1
// Copyright   : Your copyright notice
// Description :
//============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
//Check if Windows or BSD ready platform
#ifndef WIN32
	#include <pthread.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <sys/time.h>
	#include <semaphore.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <poll.h>
#else
	#include <winsocks2.h>
#endif


#define SPLIT_SIZE 2500
//Both send and receive threads cumulatively
#define MAXIMUM_THREADS 10

class UDTP{

public:
	UDTP() { m_bInitialized = false; m_iPort = 0;};
	~UDTP() {};
	//Usage: UDTP(bool m_bServerSocket, struct sockaddr_in sDestination)
	int getSocket();
	char* getDestination();
	int getPort();
	int startClient(char* chAddress, int iPort);
	int startServer(int iPort);
	int close();
private:
	void* openThread(void* args);
	static void* processThread(void* args);
	static void check();

	//Server properties
	struct sockaddr_in m_sAddress;

	//Client properties
	char* m_chAddress;
	struct sockaddr_in m_sDestination;

	//Both properties
	bool m_bServer; // Is it a server?
	int m_iSocket; //Socket file descriptor, may remove retrieval function because UDTP makes your shit simple!
	bool m_bInitialized; //Was it initialized?
	int m_iPort; //What is the port number?
	pthread_t m_MainThread;

	pthread_t rgOpenThreads[MAXIMUM_THREADS];
	struct m_sThreadProperties{
		/*	0 - Receiving Data (This will loop)
		 *  1 - Send Data
		 *  2 - Acknowledgement
		 */
		int iType;
		std::vector<char> vData;
	};
};
