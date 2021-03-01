#pragma once

#include <string>
#include <vector>

#include "symbole.h"
#include "state.h"
#include "lexer.h"

class Automate{
    public:
        Automate(std::string _e);
        ~Automate();
        void decalage(Symbole * symb, State *s);
        void addState(State * s);
        void reduction(int n,  Symbole *s);
        std::vector<State *> getStateStack();
        std::vector<Symbole *> getSymboleStack();
        void read();

    protected:
        std::string expression;
        std::vector<State *> stateStack;
        std::vector<Symbole *> symboleStack;
        Lexer * l;

};