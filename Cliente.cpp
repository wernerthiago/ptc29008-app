/*
 * Cliente.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: werner
 */

#include "Cliente.h"
#include <map>
#include <vector>
#include <string>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIME 100

using namespace std;
using boost::asio;


void ProtoClienteAPI::login(const string & nome, const string & senha){
	this->jogador = nome;
	EventoLoginReq ev(nome,senha);
	this->handle(ev);
	this->wait();
}

void ProtoClienteAPI::logout(){
	EventoLogoutReq ev(this->jogador);
	this->handle(ev);
}

void ProtoClienteAPI::join(const string & partida, const string & extra){
	EventoJoinReq ev(partida,extra);
	this->handle(ev);
}

void ProtoClienteAPI::lista_info(vector<Par> & lista){
	EventoListReq ev(lista);
	this->handle(ev);
}

void ProtoClienteAPI::leave(){
	EventoLeaveReq ev;
	this->handle(ev);
}

void ProtoClienteAPI::wait(){
	int fd = this->client.get_socket();

	struct timeval timeout; // para especificar o timeout
	timeout.tv_sec = 2; //timeout de 2 segundos
	timeout.tv_usec = 0;

	fd_set espera;
	FD_ZERO(&espera);
	FD_SET(fd, &espera);

	if (select(fd+1, &espera, NULL, NULL, &timeout) == 0) { // timeout !!
		EventoTimeout ev;
		this->handle(ev);
	} else {
		std::string recieve = client.recv();
	}
}

void ProtoClienteAPI::handle(Evento & ev){
    State * novo = estado->handle(ev);
    if (novo) {
        estado = novo;
    } else throw exception();
}
