#include <string>
#include <vector>
#include <ctime>
#include "le_arquivos.hpp"

std::string palavra_secreta;

void sorteia_palavra()
{
   std::vector<std::string> palavras = le_arquivos();

   srand(time(NULL));
   int indice_sorteado = rand() % palavras.size();

   palavra_secreta = palavras[indice_sorteado];
}