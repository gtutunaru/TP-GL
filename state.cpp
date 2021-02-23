#include "state.h"
#include <iostream>

State::State(int _id){
    id = _id;
}

State::~State(){}


void State::Affiche(){
    std::cout<<"State "<<id<<std::endl;
}
