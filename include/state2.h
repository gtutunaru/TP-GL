#pragma once

#include "state.h"

class State2 : public State {
    public:
        State2(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};