/*
 * Cliente.h
 *
 *  Created on: Nov 24, 2015
 *      Author: werner
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "types.h"
#include "Socket.h"
#include "Address.h"
#include "Evento.h"

class State;

using namespace std;

// Uma classe abstrata para implementar um objeto-função. Isso pode ser usado para
// implementar o callback para recebimento de notificações (notify)
// Deve-se especializá-la, sobrescrevendo o método "operator()"
class NotifyCallback {
public:
	virtual void operator()(const string & assunto, const vector<Par> & data) = 0;
};

// A interface de acesso ao serviço é implementada na classe ProtoClienteAPI

class ProtoClienteAPI {
protected:
	State * estado;
private:
	string ip; //o IP da outra entidade de protocolo
	unsigned short port; // o port da outra entidade de protocolo
	string jogador; // o identificador do jogador usado pelo protocolo
	NotifyCallback * notify_cb; // o callback para receber notificações ... inicialmente NULL
	Socket socket;
	Address address;
	void handle(Evento & ev);
public:
	ProtoClienteAPI(std::string ip, unsigned short port, State * inicio) {
		this->ip = ip;
		this->port = port;
		this->estado = inicio;
		Address address(ip,port);
		this->getAddress() = address;
		socket.Open(address);
	}
	~ProtoClienteAPI();

	ProtoClienteAPI getInstance(){
		return *this;
	}

	// Define o callback para receber notificações
	void set_notify(NotifyCallback & cb){
		notify_cb = &cb;
	}

	// As operações do protocolo a seguir disparam exceções quando falham

	// solicita um login no jogo
	void login(const string & nome, const string & senha);
	void lista_info(vector<Par> & lista);
	void join(const string & partida, const string & extra);
	void leave();
	void logout();
	void send(const vector<Par> & data, vector<Par> & resp);
	void subscribe(const string & assunto);
	void unsubscribe(const string & assunto);
	void publish(const string & assunto, vector<Par> & data);
	void poll_notify(const string & assunto, vector<Par> & data);
	void wait();

	Socket getSocket(){
		return this->socket;
	}

	Address getAddress(){
		return this->address;
	}
};



#endif /* CLIENTE_H_ */
