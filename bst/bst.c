#include "bst.h"
#include "stdio.h"
#include "stdlib.h"
noh *cria_noh(int chave) {

  noh *x = (noh *)malloc(sizeof(struct reg));
  x->esq = NULL;
  x->dir = NULL;
  x->chave = chave;
  

  return x;
}

noh *busca(arvore r, int k) {
  if (r == NULL || r->chave == k)
    return r;
  if (r->chave > k)
    return busca(r->esq, k);
  else
    return busca(r->dir, k);
}

arvore insere(arvore r, noh *novo) {
  
  if (r == NULL)
    return novo;

  if (r->chave > novo->chave)
    
    r->esq = insere(r->esq, novo);
  else
    r->dir = insere(r->dir, novo);
  return r;
}

arvore removeraiz(arvore r) {
  noh *p, *q;
  if (r->esq == NULL) {
    q = r->dir;
    free(r);
    return q;
  }
  p = r;
  q = r->esq;
  while (q->dir != NULL) {
    p = q;
    q = q->dir;
  }
  // q é nó anterior a r na ordem e-r-d
  // p é pai de q
  if (p != r) {
    p->dir = q->esq;
    q->esq = r->esq;
  }
  q->dir = r->dir;
  free(r);
  return q;
}


void imprime_arvore(arvore r, int t) {

  // if (t >= P)
  //  return;
  if (r != NULL) {
    for (int k = 0; k < t; k++)
      printf("_");
    if (r->chave == '*' || r->chave == '/' || r->chave == '-' ||
        r->chave == '+') {
      printf("%c\n", r->chave);
    } else
      printf("%d\n", r->chave);

    imprime_arvore(r->esq, t + 2);
    imprime_arvore(r->dir, t + 2);
  }
}

int qtnos(arvore r) {

  if (r == NULL)
    return 0;

  return qtnos(r->esq) + qtnos(r->dir) + 1;
}

void erd(arvore r, FILE *f) {

  if (r != NULL) {

    if (r->esq == NULL && r->dir == NULL) {
      
      fprintf(f, "%d\n", r->chave);
    } else {
      erd(r->esq, f);
      fprintf(f, "%d\n", r->chave);
      erd(r->dir, f);
    }
  }
}


void salva_arvore(char *arq, arvore v) {
  FILE *saida;
  int n = qtnos(v);
  saida = fopen(arq, "w");
  fprintf(saida, "%d\n", n);
  erd(v, saida);
}
