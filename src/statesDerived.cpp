#include "statesDerived.h"
#include <iostream>

bool State0::Transition(Automate * automate, Symbole *s){
    std::cout<<"STATE0"<<std::endl;

    switch (*s){
        case INT:

            break;
        case OPENPAR:
            
            break;
        case EXPR:
            
            break;
        default:
            return false;
    }
    return true;
}

bool State1::Transition(Automate * automate, Symbole *s){

}

bool State2::Transition(Automate * automate, Symbole *s){

}

bool State3::Transition(Automate * automate, Symbole *s){

}

bool State4::Transition(Automate * automate, Symbole *s){

}

bool State5::Transition(Automate * automate, Symbole *s){

}

bool State6::Transition(Automate * automate, Symbole *s){

}

bool State7::Transition(Automate * automate, Symbole *s){

}

bool State8::Transition(Automate * automate, Symbole *s){

}

bool State9::Transition(Automate * automate, Symbole *s){

}

