/*
 * packet.h
 *
 *  Created on: Sep 2, 2013
 *      Author: lucky
 */

#ifndef PACKET_H_
#define PACKET_H_

class packet{
public:
	packet(){

	};
	~packet();
	int m_iIdentifier; // which part of the packet
	char* m_chData;
};



#endif /* PACKET_H_ */
