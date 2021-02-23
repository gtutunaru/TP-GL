#include <string>
#include "symbole.h"

class Automate;

class State {
    public:
        State(int _id);
        virtual ~State();
        void Affiche();
        virtual bool Transition(Automate * automate, Symbole *s);

    protected:
        int id;
};