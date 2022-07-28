#include <iostream>
#include "imprime_palavra_forca.hpp"


void imprime_palavra_forca(std::string& palavra_secreta, std::map<char, bool>& chutou)
{
   /* Esse laço de repetição abaixo repete letra por letra da palavra_secreta o código do if, que está fazendo a substitução do underline para letra com chute certo (no map chutou) */
   for (char letra : palavra_secreta)
   {
      if (chutou[letra])
      {
         std::cout << letra << " ";
      }
      else
      {
         std::cout << "_ ";
      }
   }
   std::cout << std::endl;
}