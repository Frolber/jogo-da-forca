#include <iostream>
#include <string>
#include <vector>
#include "le_arquivos.hpp"
#include "salva_arquivo.hpp"

void adiciona_palavra()
{
   std::cout << "Digite a nova palavra." << std::endl;
   std::string nova_palavra;
   std::cin >> nova_palavra;
   /*Tratamento para deixa tudo maiusculo*/
   for (char &c : nova_palavra)
   {
      c = toupper(c);
   }

   std::vector<std::string> lista_palavras = le_arquivos();
   lista_palavras.push_back(nova_palavra);

   salva_arquivo(lista_palavras);
}