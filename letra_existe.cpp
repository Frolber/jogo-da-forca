#include "letra_existe.hpp"


/* Essa função em bool letra_existe (só retorna true ou false) vai ter um laço de repetição FOR de cada letra da palavra secreta e conferir se a letra do chute dado tem match com alguma da palavra secreta AQUI É CONFERÊNCIA*/
bool letra_existe(char chute, std::string& palavra_secreta)
{
   for (char letra : palavra_secreta)
   {
      if (chute == letra)
      {
         return true;
      }
   }
   return false;
}