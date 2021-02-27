#include <iostream>

#include "statesDerived.h"
#include "automate.h"
#include "lexer.h"


Automate::Automate(std::string _e){
    expression = _e;
    l = new Lexer(expression);
}

Automate::~Automate(){
    while (!stateStack.empty()){
        delete(stateStack.back());
        stateStack.pop_back();
    }
    while (!symboleStack.empty()){
        delete(symboleStack.back());
        symboleStack.pop_back();
    }
}

void Automate::read(){

    Symbole * s;

    State0 * state = new State0(0);
    stateStack.push_back(state);

    bool transition = true;

    while(transition){
        s=l->Consulter();
        stateStack.back()->Transition(this, s);
    }

    while(*(s=l->Consulter())!=FIN) {
        s->Affiche();
        std::cout<<std::endl;
        delete(s);
        l->Avancer();
    }
    delete (s);
}

void Automate::decalage(Symbole * symb, State *s){
    symboleStack.push_back(symb);
    stateStack.push_back(s);
}

void Automate::reduction(int n,  Symbole *s){
    for (int i=0; i<n; i++){
        delete(stateStack.back());
        delete(symboleStack.back());
        stateStack.pop_back();
        symboleStack.pop_back();
    }

    symboleStack.push_back(s);
    
}

void Automate::addState(State * s){
    stateStack.push_back(s);
}

std::vector<Symbole *> Automate::getStateStack(){
    return symboleStack;
}

