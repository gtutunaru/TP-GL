#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   std::cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   std::cout<<"("<<valeur<<")";
}

void Expression::Affiche() {
   Symbole::Affiche();
   std::cout<<"("<<valeur<<")"<<std::endl;
}

void Symbole::setId(int _ident) {
   ident = _ident;
}

