#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(int argc, char * argv[]) {
   std::string chaine;
   if (argc == 2){
      chaine = argv[1];
      Automate * automate = new Automate(chaine);
      automate->read();
   
      delete (automate);

   } else {
      std::cout<<"Please give an expression as an argument"<<std::endl;
   }

   return 0;
}

