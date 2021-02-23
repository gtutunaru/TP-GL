#pragma once

#include "state.h"

class State1 : public State {
    public:
        State1(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};