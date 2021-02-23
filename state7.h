#include "state.h"

class State7 : public State {
    public:
        State7(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};