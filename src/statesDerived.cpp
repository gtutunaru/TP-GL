#include "statesDerived.h"
#include "automate.h"
#include <iostream>


bool State0::Transition(Automate * automate, Symbole *s){
    Affiche();
    
    State3 * newState3;
    State2 * newState2;
    State1 * newState1;

    switch (*s){
        case INT:
            newState3 = new State3(3);
            automate->decalage(s, newState3);
            break;
        case OPENPAR:
            newState2 = new State2(2);
            automate->decalage(s, newState2);
            break;
        case EXPR:
            newState1 = new State1(1);
            automate->addState(newState1);
            break;
        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State1::Transition(Automate * automate, Symbole *s){
    int resultat;
    State4 * newState4;
    State5 * newState5;

    switch (*s){
        case PLUS:
            newState4 = new State4(4);
            automate->decalage(s, newState4);
            break;
        case MULT:
            newState5 = new State5(5);
            automate->decalage(s, newState5);
            break;
        case FIN:
            resultat = ((Expression *) automate->getSymboleStack().back())->getValue();
            std::cout<<"Final result : "<<resultat<<std::endl;
            return false;
        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State2::Transition(Automate * automate, Symbole *s){
    Affiche();

    State3 * newState3;
    State2 * newState2;
    State6 * newState6;

    switch (*s){
        case INT:
            newState3 = new State3(3);
            automate->decalage(s, newState3);
            break;
        case OPENPAR:
            newState2 = new State2(2);
            automate->decalage(s, newState2);
            break;
        case EXPR:
            newState6 = new State6(6);
            automate->addState(newState6);
            break;
        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State3::Transition(Automate * automate, Symbole *s){
    Affiche();

    Entier * e = (Entier *) (automate->getSymboleStack().back());
    Symbole * newExpr = new Expression(e->getValue());
    //newExpr->Affiche();
    State * lastState;
    bool trans;

    switch (*s){
        case PLUS:
            
        case MULT:

        case CLOSEPAR:

        case FIN:
            automate->reduction(1, newExpr);
            lastState = automate->getStateStack().back();
            trans = lastState->Transition(automate, newExpr);
            return trans;

        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State4::Transition(Automate * automate, Symbole *s){
    Affiche();

    State3 * newState3;
    State2 * newState2;
    State7 * newState7;

    switch (*s){
        case INT:
            newState3 = new State3(3);
            automate->decalage(s, newState3);
            break;
        case OPENPAR:
            newState2 = new State2(2);
            automate->decalage(s, newState2);
            break;
        case EXPR:
            newState7 = new State7(7);
            automate->addState(newState7);
            break;
        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State5::Transition(Automate * automate, Symbole *s){
    Affiche();

    State3 * newState3;
    State2 * newState2;
    State8 * newState8;

    switch (*s){
        case INT:
            newState3 = new State3(3);
            automate->decalage(s, newState3);
            break;
        case OPENPAR:
            newState2 = new State2(2);
            automate->decalage(s, newState2);
            break;
        case EXPR:
            newState8 = new State8(8);
            automate->addState(newState8);
            break;
        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State6::Transition(Automate * automate, Symbole *s){
    Affiche();

    State4 * newState4;
    State5 * newState5;
    State9 * newState9;
    switch (*s){
        case PLUS:
            newState4 = new State4(4);
            automate->decalage(s, newState4);
            break;
        case MULT:
            newState5 = new State5(5);
            automate->decalage(s, newState5);
            break;
        case CLOSEPAR:
            newState9 = new State9(9);
            automate->decalage(s, newState9);
            break;
        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State7::Transition(Automate * automate, Symbole *s){
    Affiche();

    std::vector<Symbole *> stateVector = automate->getSymboleStack();

    Expression * e1 = (Expression *) (stateVector.back());
    Expression * e2 = (Expression *) (stateVector.at(stateVector.size()-3));
    Symbole * newExpr = new Expression(e1->getValue() + e2->getValue());
    //newExpr->Affiche();

    State5 * newState5;
    State * lastState;
    bool trans;

    switch (*s){
        case PLUS:

        case CLOSEPAR:

        case FIN:
            automate->reduction(3, newExpr);
            lastState = automate->getStateStack().back();
            trans = lastState->Transition(automate, newExpr);
            return trans;

        case MULT:
            newState5 = new State5(5);
            automate->decalage(s, newState5);
            break;
        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State8::Transition(Automate * automate, Symbole *s){
    Affiche();

    std::vector<Symbole *> stateVector = automate->getSymboleStack();

    Expression * e1 = (Expression *) (stateVector.back());
    Expression * e2 = (Expression *) (stateVector.at(stateVector.size()-3));
    Symbole * newExpr = new Expression(e1->getValue() * e2->getValue());
    //newExpr->Affiche();

    State * lastState;
    bool trans;

    switch (*s){
        case PLUS:

        case CLOSEPAR:

        case FIN:
            
        case MULT:
            automate->reduction(3, newExpr);
            lastState = automate->getStateStack().back();
            trans = lastState->Transition(automate, newExpr);
            return trans;

        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

bool State9::Transition(Automate * automate, Symbole *s){
    Affiche();

    std::vector<Symbole *> stateVector = automate->getSymboleStack();

    Expression * e = (Expression *) (stateVector.at(stateVector.size()-2));
    Symbole * newExpr = new Expression(e->getValue());
    //newExpr->Affiche();

    State * lastState;
    bool trans;

    switch (*s){
        case PLUS:

        case CLOSEPAR:

        case FIN:
            
        case MULT:
            automate->reduction(3, newExpr);
            lastState = automate->getStateStack().back();
            trans = lastState->Transition(automate, newExpr);
            return trans;

        default:
            std::cout<<"===== ERROR ====="<<std::endl;
            return false;
    }
    return true;
}

