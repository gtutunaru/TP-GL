#include "statesDerived.h"
#include "automate.h"
#include <iostream>


bool State0::Transition(Automate * automate, Symbole *s){
    std::cout<<"STATE0"<<std::endl;

    switch (*s){
        case INT:
            State3 * newState = new State3(3);
            automate->decalage(s, newState);
            break;
        case OPENPAR:
            State2 * newState = new State2(2);
            automate->decalage(s, newState);
            break;
        case EXPR:
            State1 * newState = new State1(1);
            automate->addState(newState);
            break;
        default:
            return false;
    }
    return true;
}

bool State1::Transition(Automate * automate, Symbole *s){
    int resultat;
    switch (*s){
        case PLUS:
            State4 * newState = new State4(4);
            automate->decalage(s, newState);
            break;
        case MULT:
            State5 * newState = new State5(5);
            automate->decalage(s, newState);
            break;
        case FIN:
            resultat = ((Expression) *automate->getStateStack().back()).getValue();
            std::cout<<"Final result : "<<resultat<<std::endl;
            return false;
        default:
            return false;
    }
    return true;
}

bool State2::Transition(Automate * automate, Symbole *s){
    switch (*s){
        case INT:
            State3 * newState = new State3(3);
            automate->decalage(s, newState);
            break;
        case OPENPAR:
            State2 * newState = new State2(2);
            automate->decalage(s, newState);
            break;
        case EXPR:
            State6 * newState = new State6(6);
            automate->addState(newState);
            break;
        default:
            return false;
    }
    return true;
}

bool State3::Transition(Automate * automate, Symbole *s){
    Entier e = (Entier) *(automate->getStateStack().back());
    Symbole * newExpr = new Expression(e.getValue());
    //State lastState;
    switch (*s){
        case PLUS:
            
        case MULT:

        case CLOSEPAR:

        case FIN:
            automate->reduction(1, newExpr);
            //lastState = automate->getStateStack().back()->
            //return trans;

        default:
            return false;
    }
    return true;
}

bool State4::Transition(Automate * automate, Symbole *s){
    switch (*s){
        case INT:
            State3 * newState = new State3(3);
            automate->decalage(s, newState);
            break;
        case OPENPAR:
            State2 * newState = new State2(2);
            automate->decalage(s, newState);
            break;
        case EXPR:
            State7 * newState = new State7(7);
            automate->addState(newState);
            break;
        default:
            return false;
    }
    return true;
}

bool State5::Transition(Automate * automate, Symbole *s){
    switch (*s){
        case INT:
            State3 * newState = new State3(3);
            automate->decalage(s, newState);
            break;
        case OPENPAR:
            State2 * newState = new State2(2);
            automate->decalage(s, newState);
            break;
        case EXPR:
            State8 * newState = new State8(8);
            automate->addState(newState);
            break;
        default:
            return false;
    }
    return true;
}

bool State6::Transition(Automate * automate, Symbole *s){
    switch (*s){
        case PLUS:
            State4 * newState = new State4(4);
            automate->decalage(s, newState);
            break;
        case MULT:
            State5 * newState = new State5(5);
            automate->decalage(s, newState);
            break;
        case CLOSEPAR:
            State9 * newState = new State9(9);
            automate->decalage(s, newState);
            break;
        default:
            return false;
    }
    return true;
}

bool State7::Transition(Automate * automate, Symbole *s){
    std::vector<Symbole *> stateVector = automate->getStateStack();

    Entier e1 = (Expression) *(stateVector.back());
    Entier e2 = (Expression) *(stateVector.at(stateVector.size()-3));
    Symbole * newExpr = new Expression(e1.getValue() + e2.getValue());

    switch (*s){
        case PLUS:

        case CLOSEPAR:

        case FIN:
            automate->reduction(3, newExpr);
            break;

        case MULT:
            State5 * newState = new State5(5);
            automate->decalage(s, newState);
            break;
        default:
            return false;
    }
    return true;
}

bool State8::Transition(Automate * automate, Symbole *s){
    std::vector<Symbole *> stateVector = automate->getStateStack();

    Entier e1 = (Expression) *(stateVector.back());
    Entier e2 = (Expression) *(stateVector.at(stateVector.size()-3));
    Symbole * newExpr = new Expression(e1.getValue() * e2.getValue());

    switch (*s){
        case PLUS:

        case CLOSEPAR:

        case FIN:
            
        case MULT:
            automate->reduction(3, newExpr);
            break;

        default:
            return false;
    }
    return true;
}

bool State9::Transition(Automate * automate, Symbole *s){
    std::vector<Symbole *> stateVector = automate->getStateStack();

    Expression e = (Expression) *(stateVector.at(stateVector.size()-2));
    Symbole * newExpr = new Expression(e.getValue());

    switch (*s){
        case PLUS:

        case CLOSEPAR:

        case FIN:
            
        case MULT:
            automate->reduction(3, newExpr);
            break;

        default:
            return false;
    }
    return true;
}

