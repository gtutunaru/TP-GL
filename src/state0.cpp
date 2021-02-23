#include "state0.h"
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


