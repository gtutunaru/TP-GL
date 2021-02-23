#pragma once

#include <string>
#include <stack>

#include "symbole.h"
#include "state.h"

class Automate{
    public:
        Automate(std::string _e);
        ~Automate();
        void decalage(Symbole * symb, State *s);
        void reduction(int n,  Symbole *s);
        void read();

    protected:
        std::string expression;
        std::stack<State *> stateStack;
        std::stack<Symbole *> symboleStack;

};