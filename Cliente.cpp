/*
 * Cliente.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: werner
 */

#include "Cliente.h"
#include "singleton.h"
#include <map>
#include <vector>
#include <string>

using namespace std;

void ProtoClienteAPI::login(const string & nome, const string & senha){
	this->jogador = nome;
	char * data = nome + '#' + senha;
	Mensagem msg(data,login_req);
	this->handle(msg);
    cout << "login: nome =" << nome << ", senha =" << senha << endl;
}

void ProtoClienteAPI::logout(){
	Mensagem msg(logout_req);
	this->handle(msg);
	cout << "login: nome =" << this->jogador << endl;
}

void ProtoClienteAPI::join(const string & partida, const string & extra){
	Mensagem msg(join_req);
	this->handle(msg);
    cout << "join: nome =" << this->jogador << ", partida = " << partida;
    cout << ", extra =" << extra << endl;
}

void ProtoClienteAPI::lista_info(vector<Par> & lista){

}

void ProtoClienteAPI::leave(){
	Mensagem msg(leave_req);
	this->handle(msg);
	cout << "leave: nome=" << this->jogador << endl;
}

void ProtoClienteAPI::handle(Mensagem msg){
	this->m.Request(msg);
	char * aux = this->notify_cb;
	while(1){
		if(aux != this->notify_cb){
			msg = this->notify_cb;
			break;
		}
	}
	this->m.Request(msg);
}
