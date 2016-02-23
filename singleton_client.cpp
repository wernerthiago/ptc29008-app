#include "singleton_client.h"
#include <memory>

using namespace std;

State1 * State1::single = NULL;
State2 * State2::single = NULL;
State3 * State3::single = NULL;
State4 * State4::single = NULL;
State5 * State5::single = NULL;
State6 * State6::single = NULL;
State7 * State7::single = NULL;
State8 * State8::single = NULL;
State9 * State9::single = NULL;
State10 * State10::single = NULL;

State * State1::handle(Evento & e) {
    State * s;
    std::string data;
    ProtoClienteAPI p = p.getInstance();
    switch (e.tipo) {
        case login_req:
            s = State2::get_instance();
            data = "login_req";
            p.getSocket().Send(p.getAddress(),data);
            break;
        default:
            s = State1::get_instance();
            break;
    }
    return s;
}

State * State2::handle(Evento & e) {
//    cout << "2 -" << e << "-> ";
    State * s;
    switch (e.tipo) {
        case login_resp:
            s = State3::get_instance(); //MUDADO 1 P/ 3
            cout << "3" << endl;        //MUDADE 1 P/ 3
            break;
        default:
            e.tipo = timeout;
            s = State1::get_instance();
            cout << "1" << endl;
            break;
    }
    return s;
}

State * State3::handle(Evento& e) {
//    cout << "3 -" << e << "-> ";
    State * s;
    switch (e.tipo) {
        case logout_req:
            s = State4::get_instance();
//            cout << "4" << endl;
            break;
        case list_req:
            s = State5::get_instance();
//            cout << "5" << endl;
            break;
        case join_req:
            s = State6::get_instance();
//            cout << "6" << endl;
            break;
        case timeout:
            s = State3::get_instance();
//            cout << "3" << endl;
            //VER LÓGICA DO TIMEOUT (SUGESTÃO: FAZER VÁRIOS ESTADOS DE TIMEOUT)
            break;
        default:
            s = State3::get_instance();
            break;
    }
    return s;
}

State * State4::handle(Evento& e) { //LOGOUT_WAIT1;
//    cout << "4 -" << e << "-> ";
    State * s;
    switch (e.tipo) {
        case logout_resp:
            s = State1::get_instance();
//            cout << "1" << endl;
            break;
        default:
            e.tipo = timeout;
            s = State3::get_instance();
//            cout << "3" << endl;
            break;
    }
    return s;
}

State * State5::handle(Evento& e) { //LIST_WAIT
    State * s;
    switch (e.tipo) {
        case list_resp:
            s = State3::get_instance();
            cout << "3" << endl;
            break;
        default:
            e.tipo = timeout;
            s = State3::get_instance();
            cout << "3" << endl;
            break;
    }
    return s;
}

State * State6::handle(Evento& e) { //JOIN_WAIT
    State * s;
    switch (e.tipo) {
        case join_resp:
            s = State7::get_instance();
            cout << "7" << endl;
            break;
        default:
            e.tipo = timeout;
            s = State3::get_instance();
            cout << "3" << endl;
            break;
    }
    return s;
}

State * State7::handle(Evento& e) { //ESTADO DE JOGO
    State * s;
    switch (e.tipo) {
        case logout_req:
            s = State10::get_instance();
            cout << "10" << endl;
            break;
        case leave_req:
            s = State8::get_instance();
            cout << "8" << endl;
            break;
        case setmode_req:
            s = State9::get_instance();
            cout << "9" << endl;
            break;
        case timeout:
            s = State7::get_instance();
            cout << "7" << endl;
            //VER LÓGICA DO TIMEOUT (SUGESTÃO: FAZER VÁRIOS ESTADOS DE TIMEOUT)
            break;
    }
    return s;
}

State * State8::handle(Evento& e) { //LEAVE_WAIT
    State * s;
    switch (e.tipo) {
        case leave_resp:
            s = State3::get_instance();
            cout << "3" << endl;
            break;
        default:
            e.tipo = timeout;
            s = State7::get_instance();
            cout << "7" << endl;
    }
    return s;
}

State * State9::handle(Evento& e) { //SETMODE_WAIT
    State * s;
    switch (e.tipo) {
        case setmode_resp:
            s = State7::get_instance();
            cout << "7" << endl;
            break;
        default:
            e.tipo = timeout;
            s = State7::get_instance();
            cout << "7" << endl;
    }
    return s;
}

State * State10::handle(Evento& e) { //LOGOUT_WAIT;
    State * s;
    switch (e.tipo) {
        case logout_resp:
            s = State1::get_instance();
            cout << "1" << endl;
            break;
        default:
            e.tipo = timeout;
            s = State7::get_instance();
            cout << "7" << endl;
            break;
    }
    return s;
}
