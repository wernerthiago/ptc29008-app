/*
 * Servidor.h
 *
 *  Created on: Nov 24, 2015
 *      Author: werner
 */

#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <map>
#include <vector>
#include <string.h>

using namespace std;

// Classe abstrata que serve de base para a implementação de um jogo ...
// Ela serve para implementar as operações do jogo do ponto de vista do protocolo
class Jogo {
 public:
  Jogo();
  virtual ~Jogo();

  // verifica as credenciais do jogador. Retorna verdadeiro se login autorizado.
  virtual bool login(const string & nome, const string& senha) = 0;

  // tenta adicionar jogador a uma partida. Retorna verdadeiro em caso de sucesso.
  virtual bool join(const string & name, const string & partida, const string & extra) = 0;

  // remove jogador da partida em que se encontra
  virtual void leave(const string & name) = 0;

  // recebe dados de um jogador. Se houver dados para enviar como resposta, eles devem ser inseridos
  // em "resp"
  virtual void data(const string & name, const vector<Par> & data, vector<Par> & resp) = 0;

  // recebe uma notificação para um assunto
  virtual void notify(const string & assunto, const vector<Par> & data) = 0;

  // verifica se o assunto pode ser assinado. Retorna verdadeiro caso afirmativo.
  virtual bool subscribe(const string & name, const string & assunto) = 0;
};

// A interface de acesso ao serviço no lado do servidor
class ProtoServidorAPI {
 private:
  string IP;
  int port;

  // mapeia usuários e partidas. Se partida for "", então usuário não é membro de uma partida
  map<string,string> jogadores;

  // Os assuntos existentes no jogo. Cada assunto possui uma lista de jogadores que o assinaram.
  map<string,vector<string> > assuntos;

  // O jogo que usa o protocolo
  Jogo * jogo;
 public:
  ProtoServidorAPI(const string & IP, int port, Jogo & umJogo);
  ~ProtoServidorAPI();

  // Recebe mensagens da rede e as processa de acordo com
  // as regras do protocolo (máquina de estados).
  // Nunca retorna ...
  void serve_forever();

  // Assina algum assunto no jogo
  void subscribe(const string & assunto);

  // Cancela assinatura de um assunto
  void unsubscribe(const string & assunto);

  // Publica dados relativos a um assunto
  void publish(const string & assunto, vector<Par> & data);

};

#endif /* SERVIDOR_H_ */
