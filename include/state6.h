#pragma once

#include "state.h"

class State6 : public State {
    public:
        State6(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};