#include <iostream>
#include <string>
#include <map>

std::string palavra_secreta;
std::map<char, bool> chutou;


void imprime_palavra_forca()
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