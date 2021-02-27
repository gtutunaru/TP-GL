#pragma once

#include <string>

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR , EXPR};

const std::string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" , "EXPR"};

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      void setId(int _ident);

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      int getValue(){return valeur;};
      virtual void Affiche();
   protected:
      int valeur;
};

class Expression : public Symbole {
   public:
      Expression(int v) : Symbole(EXPR), valeur(v) { }
      ~Expression() { }
      int getValue(){return valeur;};
      virtual void Affiche();
   protected:
      int valeur;
};

