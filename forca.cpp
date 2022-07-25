#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "nao_enforcou.hpp"
#include "apresenta_jogo.hpp"
#include "le_arquivos.hpp"
#include "sorteia_palavra.hpp"
#include "imprime_chutes_errados.hpp"
#include "imprime_palavra_forca.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

int main()
{
   /* **1 PASSO - apresentação, início do jogo forca */
   apresenta_jogo();

   /* Fazer leitura de arquivo de palavras e retorna vector com palavras para o jogo funcionar */

   le_arquivos();

   /* Fazer um sorteio de palavras, só precisa de uma palavra só*/

   sorteia_palavra();

   /* Condição do jogo para acontecer */
   while (nao_acertou() && nao_enforcou())
   {
      /* Está fazendo o trabalho de exibir os chutes errados*/
      imprime_chutes_errados();

      /* **2 PASSO e 5 PASSO - Imprimindo os underline no começo do jogo! E trocando letras conforme os chutes*/
      imprime_palavra_forca();

      /* **3 PASSO - Captura o chute do jogador e avisa se acertou ou errou. Também armazena o chute errado do jogador.*/
      chuta();
   }

   cout << "Fim de jogo!" << endl;
   cout << "Essa era a palavra secreta: " << palavra_secreta << endl;
   cout << endl;
   if (nao_acertou())
   {
      cout << "Você perdeu! Tente novamente!" << endl;
   }
   else
   {
      cout << "Parabéns! Você acertou a palavra secreta!" << endl;

      cout << "Você deseja adicionar uma nova palavra no jogo? (S/N)";
      char resposta;
      cin >> resposta;
      resposta = toupper(resposta);
      if (resposta == 'S')
      {
         adiciona_palavra();
      }
   }
}