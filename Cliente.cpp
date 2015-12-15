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

void ProtoClienteAPI::login(const string & nome, const string & senha){
	this->jogador = nome;
	EventoLoginReq ev(nome,senha);
	this->handle(ev);
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
	//Método criado para esperar a resposta do servidor
	//Idealmente é necessário que exista um timeout.
	udp_client_server::udp_client client(this->IP,this->port);
	udp_client_server::udp_server server(this->IP,this->port);
	int fd = client.get_socket();

	struct timeval timeout; // para especificar o timeout
	timeout.tv_sec = 2; //timeout de 2 segundos
	timeout.tv_usec = 0;

	fd_set espera;
	FD_ZERO(&espera);
	FD_SET(fd, &espera);

	if (select(1, &espera, NULL, NULL, &timeout) == 0) { // timeout !!
		EventoTimeout ev;
		this->handle(ev);
	} else {
		//EventoResp ev_resp();
		// = server.recv()
	}
}

void ProtoClienteAPI::handle(Evento & ev){
	this->Request(ev);
}
