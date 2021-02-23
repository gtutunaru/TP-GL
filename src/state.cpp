#include "state.h"
#include <iostream>

State::State(int i){
    id = i;
}

State::~State(){}

void State::Affiche(){
    std::cout<<"State "<<id<<std::endl;
}
