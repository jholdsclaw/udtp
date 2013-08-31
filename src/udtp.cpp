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
int UDTP::startServer(int m_iPort){
	if(!m_bInitialized){
	memset(&m_sAddress, 0, sizeof(m_sAddress));
	m_sAddress.sin_port = htons(m_iPort);
	m_sAddress.sin_family = AF_INET;
	m_sAddress.sin_addr.s_addr = INADDR_ANY;
	m_iSocket = socket(AF_INET, SOCK_STREAM,0);
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
int UDTP::startClient(char* m_chAddress, int m_iPort){
	if(!m_bInitialized){
		memset(&m_sDestination, 0, sizeof(m_sDestination));
		m_sDestination.sin_addr.s_addr = atoi(m_chAddress);
		m_sDestination.sin_port = htons(m_iPort);
		m_sDestination.sin_family = AF_INET;
		m_bServer = false;
		return 0;
	}

	// Socket has been initialized already! Don't do this again!
	return 1;

}
/*	This will be the threading for all things such as receiving data, sending data, and everything else.
	It will all be declared in the argument for it's use.
*/
void* UDTP::openThread(void* args){
	struct m_sThreadProperties *sProperties = (struct m_sThreadProperties *)args;
	return (int*) 0;
}
