/*
 * file.cpp
 *
 *  Created on: Sep 2, 2013
 *      Author: lucky
 */

#include "file.h"

packet* file::getPackets(){
	return m_rgPackets;
}

int file::getNumberOfPackets(){
	return m_iTotalNumberOfPackets;
}
