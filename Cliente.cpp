/*
 * Cliente.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: werner
 */

#include "Cliente.h"
#include "singleton.h"
#include "Evento.h"
#include <map>
#include <vector>
#include <string>
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
	EventoLeaveReq ev();
	this->handle(ev);
}

void ProtoClienteAPI::wait(){
	//Método criado para esperar a resposta do servidor
	//Idealmente é necessário que exista um timeout.
}

void ProtoClienteAPI::handle(Evento ev){
	this->Request(ev);
}
