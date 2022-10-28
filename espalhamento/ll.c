#include "ll.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"



ll cria_ll(char *ch){
  ll novo;
  novo=malloc(sizeof(struct lista));
  novo->chave=malloc(7 * sizeof(char));
  strcpy(novo->chave, ch);
  novo->ocorr=1;
  novo->prox=NULL;
  return novo;
}
// Esta função recebe um inteiro x e uma
// lista encadeada le de inteiros e devolve
// o endereço de uma celula que contém x.
// Se tal celula não existe, devolve NULL.

ll busca(char *x, ll le) {
  ll p;
  p = le;
  while (p != NULL &&  strcmp(p->chave,x) != 0)
    p = p->prox;
  return p;
}

// Esta função insere uma nova celula
// em uma lista encadeada. A nova celula
// tem conteudo x e é inserida entre a
// celula p e a celula seguinte.
// (Supõe-se que p != NULL.)

void insere(char *x, ll p) {
  ll nova;
  nova = malloc(sizeof(struct lista));
  nova->chave = x;
  nova->ocorr=1;
  nova->prox = p->prox;
  p->prox = nova;
}
