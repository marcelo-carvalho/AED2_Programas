#include "shellsort.h"
#include <stdio.h>

//=============================================================================
void insercaoPorCor(int *array, int n, int cor, int h){
    for (int i = (h + cor); i < n; i+=h) {
        int tmp = array[i];
        int j = i - h;
        comparacao++;
        while ((j >= 0) && (array[j] > tmp)) {
            array[j + h] = array[j];
            j-=h;
            trocas++;
        }
        array[j + h] = tmp;
    }
}
//=============================================================================
void shellsort(int *array, int n) {
    int h = 1;
    comparacao = 0; 
    trocas = 0;

    do { h = (h * 3) + 1; } while (h < n);

    do {
        h /= 3;
        for(int cor = 0; cor < h; cor++){
            insercaoPorCor(array, n, cor, h);
        }
    } while (h != 1);

    printf("\t%d", comparacao);
    printf("\t%d", trocas);
}
//=============================================================================