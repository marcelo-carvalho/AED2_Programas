#include <stdio.h>

int main(){
    int vetor[] = {10,9,8,7,6,5,4,3,2,1};
    insercao(vetor,10);

    for(int i=0; i< 10; i++) printf("%d\n",vetor[i]);

    return 0;
}

void insercao(int *array, int n){
    int tmp;
    
    for (int i = 1; i < n-1; i++) {
      int j = i;

      while ((j > 0) && (array[j] > array[j-1])) {
         tmp = array[j];
         array[j] = array[j - 1];
         array[j-1] = tmp;
         j--;
      }
   }
}