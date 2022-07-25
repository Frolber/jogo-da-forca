#include <vector>

std::vector<char> chutes_errados;

/* confere a quantidade (size()) de chutes do vector chutes_errados se passou de cinco chances*/
bool nao_enforcou()
{
   return chutes_errados.size() < 5;
}