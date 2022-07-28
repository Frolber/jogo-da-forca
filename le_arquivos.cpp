#include <iostream>
#include <fstream>
#include "le_arquivos.hpp"

/* Fazer leitura de arquivo de palavras e retorna vector com palavras para o jogo funcionar */

std::vector<std::string> le_arquivos()
{
   std::ifstream arquivo;
   arquivo.open("palavras.txt");

   if (arquivo.is_open())
   {

      int quantidade_palavra;
      arquivo >> quantidade_palavra;

      std::vector<std::string> palavras_do_arquivo;

      for (int i = 0; i < quantidade_palavra; i++)
      {
         std::string palavra_lida;
         arquivo >> palavra_lida;
         palavras_do_arquivo.push_back(palavra_lida);
      }
      arquivo.close();
      return palavras_do_arquivo;
   }
   else
   {
      std::cout << "Não foi possível acessar o banco de palavras" << std::endl;
      exit(0);
   }
}

