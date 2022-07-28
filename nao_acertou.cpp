#include "nao_acertou.hpp"


/* A função abaixo vai dizer se a palavra Secreta foi toda descoberta e mudar o valor bool do jogo para encerrar o while do jogo. O for vai pegar letra por letra da palavra secreta e botar no if dentro. No if, confiro com essa letra acima dentro do map chutou ver se existe e depois negar ela (!) para que não possa cair na regra do return true ao não acertou*/
bool nao_acertou(std::string& palavra_secreta, const std::map<char, bool>& chutou)
{
   for (char letra : palavra_secreta)
   {
      if (chutou.find(letra) == chutou.end() || !chutou.at(letra))
      {
         return true;
      }
   }
   return false;
}