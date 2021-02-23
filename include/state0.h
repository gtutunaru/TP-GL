#pragma once

#include "state.h"

class State0 : public State {
    public:
        State0(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};