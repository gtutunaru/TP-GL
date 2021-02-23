#include <iostream>

#include "state0.h"
#include "automate.h"
#include "lexer.h"


Automate::Automate(std::string _e){
    expression = _e;
    State0 * s = new State0(0);
    stateStack.push(s);
}

Automate::~Automate(){
    while (!stateStack.empty()){
        delete(stateStack.top());
        stateStack.pop();
    }
    while (!symboleStack.empty()){
        delete(symboleStack.top());
        symboleStack.pop();
    }
}

void Automate::read(){
    Lexer l(expression);

    Symbole * s;
    while(*(s=l.Consulter())!=FIN) {
        s->Affiche();
        std::cout<<std::endl;
        delete(s);
        l.Avancer();
    }
    delete (s);
}

void Automate::decalage(Symbole * symb, State *s){
    symboleStack.push(symb);
    stateStack.push(s);
}

void Automate::reduction(int n,  Symbole *s){
    for (int i=0; i<n; i++){
        delete(stateStack.top());
        delete(symboleStack.top());
        stateStack.pop();
        symboleStack.pop();
    }
    
}

