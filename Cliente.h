/*
 * Cliente.h
 *
 *  Created on: Nov 24, 2015
 *      Author: werner
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <vector>
#include <string>
#include "singleton_client.h"
#include "types.h"
#include "UDPClient.h"

using namespace std;

// Uma classe abstrata para implementar um objeto-função. Isso pode ser usado para
// implementar o callback para recebimento de notificações (notify)
// Deve-se especializá-la, sobrescrevendo o método "operator()"
class NotifyCallback {
public:
	virtual void operator()(const string & assunto, const vector<Par> & data) = 0;
};

// A interface de acesso ao serviço é implementada na classe ProtoClienteAPI

class State;

class ProtoClienteAPI {
protected:
	State * estado;
private:
	string IP; //o IP da outra entidade de protocolo
	int port; // o port da outra entidade de protocolo
	string jogador; // o identificador do jogador usado pelo protocolo
	NotifyCallback * notify_cb; // o callback para receber notificações ... inicialmente NULL
	UDPClient client;

public:
	ProtoClienteAPI(const string & IP, int port, State * inicio) : IP(IP), port(port),
	  estado(inicio), client(boost::asio::io_service io_service,IP,port) {};
	~ProtoClienteAPI();

	// Define o callback para receber notificações
	void set_notify(NotifyCallback & cb){
		notify_cb = &cb;
	}

	// As operações do protocolo a seguir disparam exceções quando falham

	// solicita um login no jogo
	void login(const string & nome, const string & senha);

	// Solicita uma listagem, o que depende do contexto e isso depende da aplicação. Por exemplo:
	// - se cliente está logado, então obtém uma listagem das partidas existentes
	// - se cliente é membro de uma partida, obtém uma listagem dos demais participantes da partida
	// O resultado é uma lista de pares ... isso dá flexibilidade para a aplicação gerar a informação que achar
	// pertinente a cada listagem.
	void lista_info(vector<Par> & lista);

	// Entra em uma partida
	void join(const string & partida, const string & extra);

	// Sai de uma partida
	void leave();

	// Sai do jogo
	void logout();

	// Envia dados pro jogo. Usa lista de pares para enviar dados genéricos. A resposta do servidor
	// é retornada no argumento "resp"
	void send(const vector<Par> & data, vector<Par> & resp);

	// Assina algum assunto no jogo
	void subscribe(const string & assunto);

	// Cancela assinatura de um assunto
	void unsubscribe(const string & assunto);

	// Publica dados relativos a um assunto
	void publish(const string & assunto, vector<Par> & data);

	// Verifica se alguma notificação de um assunto foi recebida. Só faz sentido usar isto
	// se o callback para receber notificações não foi definido.
	void poll_notify(const string & assunto, vector<Par> & data);

	void wait();

	int get_descritor(){
		return client.get_socket();
	}

	int Request();

private:
	void handle(Evento & ev);
	// o tratador de evento da máquina de estados do protocolo
	// as operações solicitadas pela aplicação por meio dos métodos desta classe
	// são tratadas como eventos para a máquina de estados
	// Os argumentos do tratador de evento dependem da implementação de cada um ...
	//handle(...);
};



#endif /* CLIENTE_H_ */
