#include <iostream>
#include "imprime_chutes_errados.hpp"

void imprime_chutes_errados(const std::vector<char>& chutes_errados)
{
   std::cout << "Chutes errados: ";
   for (char letra : chutes_errados)
   {
      std::cout << letra << " ,";
   }
   std::cout << std::endl;
}