typedef struct reg {
  int chave;
  struct reg *esq, *dir;
} noh; // nó
typedef noh *arvore;

//recebe uma chave e cria um noh com o valor da chave

noh *cria_noh(int chave);

// Recebe uma árvore de busca r e
// um número k. Devolve um nó
// cuja chave é k; se tal nó não existe,
// devolve NULL.

noh *busca(arvore r, int k);

// A função recebe uma árvore de busca r
// e uma folha avulsa novo e insere a folha
// na árvore de modo que a árvore continue
// sendo de busca. A função devolve a raiz
// da árvore resultante.

arvore insere(arvore r, noh *novo);

// Recebe uma árvore não vazia r.
// Remove a raiz da árvore e rearranja
// a árvore de modo que ela continue sendo
// de busca. Devolve o endereço da
// nova raiz.
arvore removeraiz(arvore r);

//imprime toda a arvore evidenciandp os filhos por '_'
void imprime_arvore(arvore, int);

//recebe um nome de um arquivo e arvore que quer salvar
// e salva a arvore em ordem crescente
void salva_arvore(char *arq, arvore v);

