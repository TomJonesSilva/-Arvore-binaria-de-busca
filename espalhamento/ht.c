#include "ht.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include <stdio.h>

int hash(char *ch, int M) {
  unsigned h = 0;
  for (int i = 0; ch[i] != '\0'; i++)
    h = (h * 256 + ch[i]) % M;
  return h;
}

HT cria_ht(int M) {
  HT nova = malloc(sizeof(struct ht_struct));
  nova->tab = malloc(M * sizeof(struct lista));
  nova->M = M;
  for (int i = 0; i < M; i++)
    nova->tab[i] = NULL;
  return nova;
}

void put(HT t, char *ch) {

  int h = hash(ch, t->M);
  ll p = busca(ch, t->tab[h]);
  if (p != NULL)
    p->ocorr += 1;
  else {
    p = cria_ll(ch);
    p->prox = t->tab[h];
    t->tab[h] = p;
  }
}

int get(HT t, char *ch) {
  int h = hash(ch, t->M);
  ll p = busca(ch, t->tab[h]);
  if (p != NULL)
    return h;
  else {
    return -1;
  }
}

void printHT(HT t) {
  printf("| chave|   |ocorrencia|   |hash|\n");
  printf("\n");
  for (int i = 0; i < t->M; i++) {

    ll l = t->tab[i];
    while (l != NULL) {
      printf("|%s|   |     %d    |    | %d |", l->chave, l->ocorr,
             get(t, l->chave));
      printf("\n");
      l = l->prox;
    }
    printf("\n");
  }
}
void imprimeArquivo(HT t, FILE *saida) {
  for (int i = 0; i < t->M; i++) {
    ll l = t->tab[i];
    while (l != NULL) {
      fprintf(saida, "%s %d\n", l->chave, l->ocorr);
      l = l->prox;
    }
  }
}