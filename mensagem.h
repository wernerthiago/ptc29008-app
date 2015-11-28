/* 
 * File:   mensagem.h
 * Author: alvinegro
 *
 * Created on 26 de Outubro de 2015, 15:35
 */

#ifndef MENSAGEM_H
#define	MENSAGEM_H

#include "singleton.h"

enum Event {
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

class Mensagem{
public:
	Mensagem(Event e){
		this->e = e;
		this->data = NULL;
	}
	Mensagem(char * data,Event e){
		this->data = data;
		this->e = e;
	}
	char * get_data(){
		return this->data;
	}
	Event get_event(){
		return this->e;
	}
	void set_event(Event e){
		this->e = e;
	}
	void set_data(char * data){
		this->data = data;
	}
private:
	Event e;
	char * data[1024];
};

#endif	/* MENSAGEM_H */

