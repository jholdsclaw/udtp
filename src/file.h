/*
 * file.h
 *
 *  Created on: Sep 2, 2013
 *      Author: lucky
 */
#include "packet.h"
#include <fstream>
#ifndef FILE_H_
#define FILE_H_

class file{
public:
	int m_iTotalNumberOfPackets;
	std::fstream m_FileInput;
	file(){

	};
	~file();
	packet* getPackets();
	int getNumberOfPackets();
	packet m_rgPackets[];
};


#endif /* FILE_H_ */
