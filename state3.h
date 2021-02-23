#include "state.h"

class State3 : public State {
    public:
        State3(int i):State(i){};
        bool Transition(Automate * automate, Symbole *s);
};