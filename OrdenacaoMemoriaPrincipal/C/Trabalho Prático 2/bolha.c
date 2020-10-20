#include "geracao.h"
#include "bolha.h"
#include <stdio.h>
//=============================================================================
void bolha(int *array, int n){
    int i, j;
    comparacao = 0; 
    trocas = 0;
    
    for (i = (n - 1); i > 0; i--) {
      for (j = 0; j < i; j++) {
         comparacao++;
         if (array[j] > array[j + 1]) {
            swap(&array[j], &array[j + 1]);
            trocas++;
         }
      }
   }
   printf("\t%d", comparacao);
   printf("\t%d", trocas);
}
//=============================================================================