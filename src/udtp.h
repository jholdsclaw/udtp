//============================================================================
// Name        : UDP-based file transfer (UDTP)
// Author      : Lucky
// Version     : 0.1
// Copyright   : Your copyright notice
// Description :
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

class UDTP{
public:
	//Usage: UDTP(bool m_bServerSocket, struct sockaddr_in sDestination)
	UDTP();
	int getSocket();
	char* getDestination();
	int getPort();
	int startClient(char* m_chAddress, int m_iPort);
	int startServer(int m_iPort);
	~UDTP();
private:

	//Server properties
	bool m_bServer;
	struct sockaddr_in m_sAddress;


	//Client properties
	char* m_chAddress;
	struct sockaddr_in m_sDestination;

	//Both properties
	int m_iSocket;
	bool m_bInitialized;
	int m_iPort;
};
