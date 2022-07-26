#include <iostream>
#include "letra_existe.hpp"
#include "chuta.hpp"

void chuta(std::map<char, bool>& chutou, std::vector<char>& chutes_errados, std::string& palavra_secreta)
{
   std::cout << "Qual a letra que tem na palavra acima? ";
   char chute;
   std::cin >> chute;
   chute = toupper(chute);
   std::cout << std::endl;

	chutou[chute] = true; /*Todas letras dos chutes vão receber true no quesito de saber se já foram chutadas.*/

   /* Avisa ao jogador se acertou ou errou o chute. Se errou, guarda o erro no vector chutes_errados*/
   if (letra_existe(chute, palavra_secreta))
   {
      std::cout << "Você acertou! Seu chute está na palavra!" << std::endl;
   }
   else
   {
      std::cout << "Você errou... Seu chute não está na palavra!" << std::endl;
      chutes_errados.push_back(chute);
   }
   std::cout << std::endl;
}