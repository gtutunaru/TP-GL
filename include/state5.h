#pragma once

#include "state.h"

class State5 : public State {
    public:
        State5(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};