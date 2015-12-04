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

}

void ProtoClienteAPI::handle(Evento ev){
	this->m.Request(ev);
}
