#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <vector>

using namespace std;

// códigos de retorno para operações do protocolo
enum Codigos_Retorno {
	OK,
	ERRO,
	RECUSADO,
	TIMEOUT
};

// um par atributo, valor, usado para as trocas de dados entre entidades do protocolo
struct Par {
	string atributo;
	string valor;
};

#endif
