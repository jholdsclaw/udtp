/*
 * main.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: lucky
 */

#include "udtp.h"

int main(int argc, char* argv[]){
	std::cout << "Runs from main" << std::endl;
	UDTP master;
	int result;
	result = master.startServer(6665);
	std::cout << "Result " << result << " and Port is " << master.getPort() << std::endl;
	while(true){

		poll(0,0,100);
	}
	return 0;
}

