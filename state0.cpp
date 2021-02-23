#include "state0.h"

bool State0::Transition(Automate * automate, Symbole *s){
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
