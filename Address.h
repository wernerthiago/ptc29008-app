/*
 * Address.h
 *
 *  Created on: Feb 21, 2016
 *      Author: werner
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <netinet/in.h>
#include <string>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <map>
#include <sys/select.h>
#include <sys/time.h>

class Address {
public:
	Address();
	Address(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port);
	Address(std::string ip, unsigned short port);
	std::string GetAddress();
	unsigned char GetA(){
		return a;
	}
	unsigned char GetB(){
		return b;
	}
	unsigned char GetC(){
		return c;
	}
	unsigned char GetD(){
		return d;
	}
//	struct sockaddr_in GetAddr(){
//		return myaddr;
//	}
	unsigned short GetPort() const;
	struct sockaddr_in myaddr;
private:
	std::string address;
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
	unsigned short port;
};

#endif /* ADDRESS_H_ */
