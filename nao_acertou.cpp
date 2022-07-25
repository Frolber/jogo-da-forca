#include <string>
#include <map>

std::string palavra_secreta;
std::map<char, bool> chutou;

/* A função abaixo vai dizer se a palavra Secreta foi toda descoberta e mudar o valor bool do jogo para encerrar o while do jogo. O for vai pegar letra por letra da palavra secreta e botar no if dentro. No if, confiro com essa letra acima dentro do map chutou ver se existe e depois negar ela (!) para que não possa cair na regra do return true ao não acertou*/
bool nao_acertou()
{
   for (char letra : palavra_secreta)
   {
      if (!chutou[letra])
      {
         return true;
      }
   }
   return false;
}