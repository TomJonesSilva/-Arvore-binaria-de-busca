#include "bst.h"
#include "pq.h"
#include "time.h"
#include <stdio.h>

int main(void) {
 
  
  
  // variaveis para calcular o tempo de execução
  time_t t_ini, t_fim;
  float tempo;
  double time_spent = 0.0;

  // primeira bateria de teste

  // lendo o arquivo de entrada
  FILE *entrada;
  entrada = fopen("dados1.in", "r");

  // pegando o tamanho da entrada
  int n;
  fscanf(entrada, "%d", &n);
  // pegando  o primeiro inteiro da sequencia para usar como a raiz
  int raiz;
  fscanf(entrada, "%d", &raiz);

  // teste com a arvore de busca
  clock_t ini = clock();

  arvore arv = cria_noh(raiz);


  
  for (int i = 1; i < n; i++) {
    int x;
    fscanf(entrada, "%d", &x);
    noh *no = cria_noh(x);
    insere(arv, no);
  }



  
   salva_arvore("bst.out",arv);

  clock_t fim = clock();

  time_spent = (double)(fim - ini) / CLOCKS_PER_SEC;
  printf("\n\n\n%f", time_spent);

  fclose(entrada);



  
  // teste com a fila de prioridade
  ini = clock();

  pq fil = loadpq();
   savepq(fil);

  fim = clock();

  time_spent = (double)(fim - ini) / CLOCKS_PER_SEC;
  printf("\n\n\n%f", time_spent);

  // segunda bateria de teste usando o pior caso para uma arvore de
  // busca(inteiros ordenados)
  FILE *t;
  t = fopen("dados.in", "r");
  int primeiro, segundo;
  fscanf(t, "%d", &primeiro);
  fscanf(t, "%d", &segundo);

  arvore pc = cria_noh(segundo);

  ini = clock();

  for (int i = 1; i < primeiro; i++) {
    int x;
    fscanf(t, "%d", &x);
    noh *no = cria_noh(x);
    insere(pc, no);
  }

  fim = clock();
  time_spent = (double)(fim - ini) / CLOCKS_PER_SEC;
  printf("\n\n\n%f", time_spent);
  printf("\n\n");

  







  
  return 0;
}