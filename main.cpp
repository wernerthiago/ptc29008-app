/*
 * main.cpp
 *
 *  Created on: Nov 24, 2015
 *      Author: werner
 */

#include "singleton.h"

int main() {
    State1 * s = State1::get_instance();
    Context m(s);
    Event e;

    e = login_req;
    m.Request(e);

    e = login_resp;
    m.Request(e);

    e = list_req;
    m.Request(e);

    e = list_resp;
    m.Request(e);

    e = join_req;
    m.Request(e);

    e = join_resp;
    m.Request(e);

    e = setmode_req;
    m.Request(e);

    e = setmode_resp;
    m.Request(e);

    e = logout_req;
    m.Request(e);

    e = logout_resp;
    m.Request(e);
}

