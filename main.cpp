/*
 * main.cpp
 *
 *  Created on: Nov 24, 2015
 *      Author: werner
 */

#include "singleton.h"

int main() {
    State1 * s = State1::get_instance();
    Context m = s;
    Mensagem msg("tst",login_req);

    m.Request(msg);

    msg.set_event(login_resp);
    m.Request(msg);
    msg.set_event(list_req);
    m.Request(msg);
}

