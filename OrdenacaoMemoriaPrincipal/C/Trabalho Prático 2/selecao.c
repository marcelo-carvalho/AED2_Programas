#include "selecao.h"
#include <stdio.h>

//=============================================================================
void selecao(int *array, int n){
    comparacao = 0;
    trocas = 0;
    
    for (int i = 0; i < (n - 1); i++) {
      int menor = i;
      for (int j = (i + 1); j < n; j++){
         if (array[menor] > array[j]){
            comparacao++;
            menor = j;
         }
      }
      swap(&array[menor], &array[i]);
      trocas++;
   }
}
//=============================================================================