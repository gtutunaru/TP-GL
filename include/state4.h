#pragma once

#include "state.h"

class State4 : public State {
    public:
        State4(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};