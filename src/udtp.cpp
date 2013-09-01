//============================================================================
// Name        : UDP-based file transfer (UDTP)
// Author      : Lucky
// Version     : 0.1
// Copyright   : Your copyright notice
// Description :
//============================================================================
#include "udtp.h"

int UDTP::getSocket(){
	return m_iSocket;
}

int UDTP::getPort(){
	return m_iPort;
}
char* UDTP::getDestination(){
	return m_chAddress;
}
/*	Method: startServer()
	Usage: Starts the server.
	Return: 0 on successful
			1 socket has been initialized already!
			2 could not bind
			3 could not listen
*/
int UDTP::startServer(int iPort){
	if(!m_bInitialized){
		UDTP::m_iPort = iPort;
		memset(&m_sAddress, 0, sizeof(m_sAddress));
		m_sAddress.sin_port = htons(m_iPort);
		m_sAddress.sin_family = AF_INET;
		m_sAddress.sin_addr.s_addr = INADDR_ANY;
		m_iSocket = socket(AF_INET, SOCK_DGRAM,0);
	if((bind(m_iSocket, (struct sockaddr*)&m_sAddress, sizeof(m_sAddress)))<0){
		perror("bind");
		return 2;
	}
	if((listen(m_iSocket, 0))<0){
		perror("listen");
		return 3;
	}
	m_bServer = true;
	m_bInitialized = true;


	pthread_create(&m_MainThread, NULL, &UDTP::processThread, NULL);
	pthread_tryjoin_np(m_MainThread, NULL);
	return 0;

	}

	// Socket has already been initialized! Do not initialize again!
	return 1;
}


/*	Method: startClient(char* DESTINATION_ADDRESS, int DESTINATION_PORT)
	Usage: Starts a client socket
	Return: 0 on successful
			1 socket has been initialized already!

*/
int UDTP::startClient(char* chAddress, int iPort){
	if(!m_bInitialized){
		UDTP::m_chAddress = chAddress;
		UDTP::m_iPort = iPort;
		memset(&m_sDestination, 0, sizeof(m_sDestination));
		m_sDestination.sin_addr.s_addr = atoi(m_chAddress);
		m_sDestination.sin_port = htons(m_iPort);
		m_sDestination.sin_family = AF_INET;
		m_iSocket = socket(AF_INET, SOCK_DGRAM, 0);
		m_bServer = false;
		pthread_create(&m_MainThread, NULL, &UDTP::processThread, (void*)this);
		pthread_tryjoin_np(m_MainThread, NULL);
		return 0;
	}

	// Socket has been initialized already! Don't do this again!
	return 1;

}
int UDTP::close(){
	if(m_bInitialized){
		m_bInitialized = false;
	}
	return 0;

}

/*	This will handle everything that goes on with the server, such as queueing up requests and listening to whines.
 *	This is the main part of UDTP.
 *
 *	... I need more ram
 */
void *UDTP::processThread(void* args){
	//Not working! Find out how to pass member variables to thread!
	UDTP *CProperties = (UDTP*) args;
	while(true){

	poll(0, 0, 1000);
	}

	return NULL;
}
/*	This will be the threading for all things such as sending data and receiving data
	It will all be declared in the argument for it's use.
	It will also whine requests if something goes wrong and close itself until processThread opens another one again
*/
void* UDTP::openThread(void* args){
	struct m_sThreadProperties *sProperties = (struct m_sThreadProperties *)args;
	return (int*) 0;
}

