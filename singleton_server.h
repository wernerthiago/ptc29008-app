/*
 * singleton_server.h
 *
 *  Created on: Dec 22, 2015
 *      Author: werner
 */

#ifndef SINGLETON_SERVER_H_
#define SINGLETON_SERVER_H_

#include "Evento.h"
#include "types.h"

class State {
public:
    virtual State * handle(Evento & ev) = 0;
    virtual ~State();
};

class StateIdle : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static StateIdle * get_instance() {
        if (not single) single = new StateIdle();
        return single;
    }

    virtual State * handle(Evento & e);
private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    StateIdle() {
    }

    State1(const StateIdle & outro) {
    }

    StateIdle& operator=(const State1 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static StateIdle * single;

};


class State1 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State1 * get_instance() {
        if (not single) single = new State1();
        return single;
    }

    virtual State * handle(Evento & e);
private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State1() {
    }

    State1(const State1 & outro) {
    }

    State1& operator=(const State1 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State1 * single;

};

class State2 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State2 * get_instance() {
        if (not single) single = new State2();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State2() {

    }

    State2(const State2 & outro) {

    }

    State2& operator=(const State2 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State2 * single;
};

class State21 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State21 * get_instance() {
        if (not single) single = new State21();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State21() {

    }

    State2(const State21 & outro) {

    }

    State21& operator=(const State21 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State21 * single;
};

class State3 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State3 * get_instance() {
        if (not single) single = new State3();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State3() {

    }

    State3(const State3 & outro) {

    }

    State3& operator=(const State3 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State3 * single;
};

class State4 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State4 * get_instance() {
        if (not single) single = new State4();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State4() {

    }

    State4(const State4 & outro) {

    }

    State4& operator=(const State4 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State4 * single;
};

class State41 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State41 * get_instance() {
        if (not single) single = new State41();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State41() {

    }

    State41(const State41 & outro) {

    }

    State41& operator=(const State41 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State41 * single;
};

class State5 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State5 * get_instance() {
        if (not single) single = new State5();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State5() {

    }

    State5(const State5 & outro) {

    }

    State5& operator=(const State5 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State5 * single;
};

class State6 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State6 * get_instance() {
        if (not single) single = new State6();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State6() {

    }

    State6(const State6 & outro) {

    }

    State6& operator=(const State6 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State6 * single;
};

class State7 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State7 * get_instance() {
        if (not single) single = new State7();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State7() {

    }

    State7(const State7 & outro) {

    }

    State7& operator=(const State7 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe,
public:
    static State7 * single;
};

class State8 : public State {
public:
    // a instância de State0 somente pode ser obtida por meio de get_instance

    static State8 * get_instance() {
        if (not single) single = new State8();
        return single;
    }

    virtual State * handle(Evento & e);

private:
    // construtor, construtor de cópia e operador de atribuição ficam inacessíveis
    // fora da classe

    State8() {

    }

    State8(const State8 & outro) {

    }

    State8& operator=(const State8 & outro) {
        return *this;
    }

    // ponteiro para a única instância da classe
public:
    static State8 * single;
};

#endif /* SINGLETON_SERVER_H_ */
