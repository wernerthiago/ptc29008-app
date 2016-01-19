#include "singleton_server.h"
#include <iostream>
#include <memory>
#include <vector>
#include "Servidor.h"

using namespace std;

StateIdle * StateIdle::single = NULL;
State1 * State1::single = NULL;
State2 * State2::single = NULL;
State21 * State21::single = NULL;
State3 * State3::single = NULL;
State4 * State4::single = NULL;
State41 * State41::single = NULL;
State5 * State5::single = NULL;
State6 * State6::single = NULL;
State7 * State7::single = NULL;
State8 * State8::single = NULL;

State * StateIdle::handle(Evento & e) {
    State * s;
    switch (e) {
        case login_req:
            s = State1::get_instance();
            //montando a mensagem ASN1
            break;
        default:
            s = StateIdle::get_instance();
            break;
    }
    return s;
}

State * State1::handle(Evento & e) {
    State * s;
    switch (e) {
        case login_resp:
            s = State2::get_instance();
            break;
        default:
            s = StateIdle::get_instance();
            break;
    }
    return s;
}

State * State2::handle(Evento& e) {
    State * s;
    switch (e) {
        case logout_req:
            s = State21::get_instance();
            break;
        case list_req:
            s = State3::get_instance();
            break;
        case join_req:
            s = State3::get_instance();
            break;
        case timeout:
            s = State2::get_instance();
            break;
        default:
            s = State2::get_instance();
            break;
    }
    return s;
}

State * State21::handle(Evento& e) {
    State * s;
    switch (e) {
        case logout_resp:
            s = StateIdle::get_instance();
            break;
        default:
            s = State2::get_instance();
            break;
    }
    return s;
}

State * State3::handle(Evento& e) { //LOGOUT_WAIT1;
    State * s;
    switch (e) {
        case join_resp:
            s = State4::get_instance();
            break;
        case list_resp:
            s = State2::get_instance();
            break;
        default:
            s = State2::get_instance();
            break;
    }
    return s;
}

State * State4::handle(Evento& e) {
    State * s;
    switch (e) {
        case logout_req:
            s = State41::get_instance();
            break;
        case setmode_req:
        	s = State6::get_instance();
        	break;
        case leave_req:
        	s = State5::get_instance();
        	break;
        case subscribe_req:
        	s = State7::get_instance();
        	break;
        case notify_req:
        	s = State8::get_instance();
        	break;
        default:
            s = State4::get_instance();
            break;
    }
    return s;
}

State * State41::handle(Evento& e) {
    State * s;
    switch (e) {
        case logout_resp:
            s = StateIdle::get_instance();
            break;
        default:
            s = State4::get_instance();
            break;
    }
    return s;
}

State * State5::handle(Evento& e) {
    State * s;
    switch (e) {
        case leave_resp:
            s = State4::get_instance();
            break;
        default:
            s = State4::get_instance();
            break;
    }
    return s;
}

State * State6::handle(Evento& e) {
    State * s;
    switch (e) {
        case setmode_resp:
            s = State4::get_instance();
            break;
        default:
            s = State4::get_instance();
            break;
    }
    return s;
}

State * State7::handle(Evento& e) {
    State * s;
    switch (e) {
        case subscribe_resp:
            s = State4::get_instance();
            break;
        default:
            s = State4::get_instance();
            break;
    }
    return s;
}

State * State8::handle(Evento& e) {
    State * s;
    switch (e) {
        case notify_resp:
            s = State4::get_instance();
            break;
        default:
            s = State4::get_instance();
            break;
    }
    return s;
}
