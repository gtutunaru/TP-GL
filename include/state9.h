#pragma once

#include "state.h"

class State9 : public State {
    public:
        State9(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};