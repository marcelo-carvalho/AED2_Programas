#include "insercao.h"
#include <stdio.h>
#include <stdlib.h>
//=============================================================================
void insercao(int *array, int n){
   comparacao = 0; 
   trocas = 0;
   for (int i = 1; i < n; i++) {
      int tmp = array[i];
      int j = i - 1;

      
      while ((j >= 0) && (array[j] > tmp)) {
         comparacao++;
         array[j + 1] = array[j];
         j--;
         trocas++;
      }
      array[j+1] = tmp;
   }
   printf("\t%d", comparacao);
   printf("\t%d", trocas);
}
//=============================================================================