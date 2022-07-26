#include <iostream>
#include <fstream>
#include "salva_arquivo.hpp"

void salva_arquivo(std::vector<std::string> lista)
{
   std::ofstream arquivo;
   arquivo.open("palavras.txt");
   if (arquivo.is_open())
   {
      arquivo << lista.size() << std::endl;

      for (std::string palavras : lista)
      {
         arquivo << palavras << std::endl;
      }

      arquivo.close();
   }
   else
   {
      std::cout << "Não foi possível acessar o banco de palavras" << std::endl;
      exit(0);
   }
}