#include "ht.h"
#include "string.h"
#include <stdbool.h>
#include <stdio.h>
int main(void) {

  FILE *entrada;
  entrada = fopen("sequences.fasta.txt", "r");
  HT t = cria_ht(10);
  char n[7];

  while (true) {

    char s[61];
    int k = fscanf(entrada, "%s", s);

    if (k != 1)
      break;

    int cont = 0;
    // para cada linha pega a sequencia de caracteres em 10 blocos de 6
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 6; j++) {
        n[j] = s[cont];
        cont++;
      }
      n[6] = '\0';
      put(t, n);
    }
  }

  FILE *saida;
  saida = fopen("conta_genoma.out", "w");
  imprimeArquivo(t, saida);

  return 0;
}