#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   std::string chaine("(1+34)*123");

   Automate * automate = new Automate(chaine);
   automate->read();
   
   return 0;
}

