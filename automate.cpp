#include <iostream>

#include "automate.h"
#include "lexer.h"
#include "state0.h"

Automate::Automate(std::string _e){
    expression = _e;
    State * s = new State0(0);
    stateStack.push(s);
}

void Automate::read(){
    Lexer l(expression);

    Symbole * s;
    while(*(s=l.Consulter())!=FIN) {
        s->Affiche();
        std::cout<<std::endl;
        l.Avancer();
    }
}

void Automate::decalage(Symbole * symb, State *s){
    symboleStack.push(symb);
    stateStack.push(s);
}

void Automate::reduction(int n,  Symbole *s){
    for (int i=0; i<n; i++){
        stateStack.pop();
        symboleStack.pop();
    }
    
}

