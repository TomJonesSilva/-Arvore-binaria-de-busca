#include "stdio.h"

struct lista{
char *chave;
int ocorr;
struct lista *prox;
};
typedef struct lista* ll;

//Recebe um chave ch e aloca um novo espaco na memoria
//com o valor da chave recebida
ll cria_ll(char *ch);

// Esta função recebe um inteiro x e uma
// lista encadeada le de inteiros e devolve
// o endereço de uma celula que contém x.
// Se tal celula não existe, devolve NULL.

ll busca (char *x, ll le);

// Esta função insere uma nova celula
// em uma lista encadeada. A nova celula
// tem conteudo x e é inserida entre a
// celula p e a celula seguinte.
// (Supõe-se que p != NULL.)

void insere (char *x, ll p);
