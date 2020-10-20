#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>

//=============================================================================
void quicksortRec(int *array, int esq, int dir) {
    int i = esq, j = dir;
    int pivo = array[(dir+esq)/2];
     
    while (i <= j) {
        while (array[i] < pivo) {comparacao++; i++;}
        while (array[j] > pivo) {comparacao++; j--;}
        if (i <= j) {
            swap(array + i, array + j);
            trocas++;
            i++;
            j--;
        }
    }
    if (esq < j)  quicksortRec(array, esq, j);
    if (i < dir)  quicksortRec(array, i, dir);
}
//=============================================================================
void quicksort(int *array, int n) {
    comparacao = 0;
    trocas = 0;

    quicksortRec(array, 0, n-1);

    printf("\t%d", comparacao);
    printf("\t%d", trocas);
}
//=============================================================================
