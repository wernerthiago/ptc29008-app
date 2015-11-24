/* 
 * File:   mensagem.h
 * Author: alvinegro
 *
 * Created on 26 de Outubro de 2015, 15:35
 */

#ifndef MENSAGEM_H
#define	MENSAGEM_H

class Mensagem{
public:
    void tratacodigo(int cod);
    
private:
    int cod;
    char * payload[1024];
};

#endif	/* MENSAGEM_H */

