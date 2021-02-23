#pragma once

#include "state.h"

class State8 : public State {
    public:
        State8(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};