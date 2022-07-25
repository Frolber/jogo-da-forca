#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;

vector<char> chutes_errados;

/* Essa função em bool letra_existe (só retorna true ou false) vai ter um laço de repetição FOR de cada letra da palavra secreta e conferir se a letra do chute dado tem match com alguma da palavra secreta AQUI É CONFERÊNCIA*/
bool letra_existe(char chute)
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

/* confere a quantidade (size()) de chutes do vector chutes_errados se passou de cinco chances*/
bool nao_enforcou()
{
   return chutes_errados.size() < 5;
}

void apresenta_jogo()
{
   cout << "********************************" << endl;
   cout << "* Bem vindes ao jogo da forca! *" << endl;
   cout << "********************************" << endl;
   cout << endl;

   cout << "Existe uma palavra secreta e tu precisa adivinhar por letras!" << endl;
}

vector<string> le_arquivos()
{
   ifstream arquivo;
   arquivo.open("palavras.txt");

   if (arquivo.is_open())
   {

      int quantidade_palavra;
      arquivo >> quantidade_palavra;

      vector<string> palavras_do_arquivo;

      for (int i = 0; i < quantidade_palavra; i++)
      {
         string palavra_lida;
         arquivo >> palavra_lida;
         palavras_do_arquivo.push_back(palavra_lida);
      }
      arquivo.close();
      return palavras_do_arquivo;
   }
   else
   {
      cout << "Não foi possível acessar o banco de palavras" << endl;
      exit(0);
   }
}

void sorteia_palavra()
{
   vector<string> palavras = le_arquivos();

   srand(time(NULL));
   int indice_sorteado = rand() % palavras.size();

   palavra_secreta = palavras[indice_sorteado];
}

void imprime_chutes_errados()
{
   cout << "Chutes errados: ";
   for (char letra : chutes_errados)
   {
      cout << letra << " ,";
   }
   cout << endl;
}

void imprime_palavra_forca()
{
   /* Esse laço de repetição abaixo repete letra por letra da palavra_secreta o código do if, que está fazendo a substitução do underline para letra com chute certo (no map chutou) */
   for (char letra : palavra_secreta)
   {
      if (chutou[letra])
      {
         cout << letra << " ";
      }
      else
      {
         cout << "_ ";
      }
   }
   cout << endl;
}

void chuta()
{
   cout << "Qual a letra que tem na palavra acima? ";
   char chute;
   cin >> chute;
   chute = toupper(chute);
   cout << endl;

   chutou[chute] = true; /*Todas letras dos chutes vão receber true no quesito de saber se já foram chutadas.*/

   /* Avisa ao jogador se acertou ou errou o chute. Se errou, guarda o erro no vector chutes_errados*/
   if (letra_existe(chute))
   {
      cout << "Você acertou! Seu chute está na palavra!" << endl;
   }
   else
   {
      cout << "Você errou... Seu chute não está na palavra!" << endl;
      chutes_errados.push_back(chute);
   }
   cout << endl;
}

void salva_arquivo(vector<string> lista)
{
   ofstream arquivo;
   arquivo.open("palavras.txt");
   if (arquivo.is_open())
   {
      arquivo << lista.size() << endl;

      for (string palavras : lista)
      {
         arquivo << palavras << endl;
      }

      arquivo.close();
   }
   else
   {
      cout << "Não foi possível acessar o banco de palavras" << endl;
      exit(0);
   }
}

void adiciona_palavra()
{
   cout << "Digite a nova palavra." << endl;
   string nova_palavra;
   cin >> nova_palavra;
   /*Tratamento para deixa tudo maiusculo*/
   for (char &c : nova_palavra)
   {
      c = toupper(c);
   }

   vector<string> lista_palavras = le_arquivos();
   lista_palavras.push_back(nova_palavra);

   salva_arquivo(lista_palavras);
}

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