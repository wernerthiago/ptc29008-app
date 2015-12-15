/* 
 * File:   mensagem.h
 * Author: alvinegro
 *
 * Created on 26 de Outubro de 2015, 15:35
 */

#ifndef EVENTO_H
#define	 EVENTO_H

//#include "singleton.h"
#include <string>
#include <vector>
#include "types.h"
//#include "Cliente.h"

using namespace std;

enum Tipo {
	login_req,
	login_resp,
	logout_req,
	logout_resp,
	join_req,
	join_resp,
	leave_req,
	leave_resp,
	list_req,
	list_resp,
	setmode_req,
	setmode_resp,
	data,
	ack,
	timeout,
	subscribe,
	unsubscribe,
	notify
};

class Evento{
public:

protected:
	Tipo tipo;
};

class EventoLoginReq : public Evento {
protected:
	string nome;
	string senha;
public:
	EventoLoginReq(const string & nome, const string & senha){
		this->tipo = login_req;
		this->nome = nome;
		this->senha = senha;
	}
	virtual ~EventoLoginReq();
	string get_nome(){
		return nome;
	}
	string get_senha(){
		return senha;
	}
};

class EventoLogoutReq : public Evento {
protected:
	string nome;
public:
	EventoLogoutReq(const string & nome){
		this->tipo = logout_req;
		this->nome = nome;
	}
	virtual ~EventoLogoutReq();
	string get_nome(){
		return this->nome;
	}
};

class EventoJoinReq : public Evento {
protected:
	string partida;
	string extra;
public:
	EventoJoinReq(const string & partida, const string & extra){
		this->tipo = join_req;
		this->partida = partida;
		this->extra = extra;
	}
	virtual ~EventoJoinReq();
};

class EventoListReq : public Evento {
protected:
	vector<Par> & lista;
public:
	EventoListReq(vector<Par> & umaLista) : lista(umaLista) {
		this->tipo = list_req;
	}
	virtual ~EventoListReq();
	vector<Par> & get_lista(){
		return this->lista;
	}
};

class EventoLeaveReq : public Evento{
public:
	EventoLeaveReq(){
		this->tipo = leave_req;
	}
	virtual ~EventoLeaveReq();
};

class EventoTimeout : public Evento{
public:
	EventoTimeout(){
		this->tipo = timeout;
	}
	virtual ~EventoTimeout();
};

#endif	/* EVENTO_H */

