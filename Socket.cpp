/*
 * Socket.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: werner
 */

#include "Socket.h"

using namespace std;

Socket::Socket() {
	// TODO Auto-generated constructor stub

}

Socket::~Socket() {
	// TODO Auto-generated destructor stub
}

bool Socket::Open(Address address) {
	if((this->fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))<0) {
		return false;
	}else{
		if(bind(this->fd,( struct sockaddr *) &address.myaddr, sizeof(address.myaddr))<0) {
			std::cout << "Erro no bind" << std::endl;
			return false;
		}
		inet_pton(AF_INET,address.GetAddress().c_str(),&address.myaddr.sin_addr.s_addr);
		address.myaddr.sin_port=htons(1234);
		return true;
	}
}

void Socket::Close() {
	close(this->fd);
}

bool Socket::Send(Address address, std::string data) {
	if(sendto(this->fd, data.c_str(), data.size(), 0, (struct sockaddr *)&address.myaddr, sizeof(address.myaddr))!=data.size()){
		std::cout << "Erro no envio do pacote!" << std::endl;
		return false;
	}else{
		return true;
	}
}

std::string Socket::Receive(Address sender) {
	int received(0);
	char data[256];
	int addrLength = sizeof(sender.myaddr);
	if((received = recvfrom(this->fd,data,sizeof(data),0,(sockaddr *)&sender.myaddr,(socklen_t*)&addrLength)) < 0) {
		std::cout << "Erro na recepcao do pacote!" << std::endl;
		return 0;
	}else{
		std::string ss = data;
		return ss;
	}
}
