#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>

//=============================================================================
void constroi(int *array, int tamHeap){
    for(int i = tamHeap; i > 1 && array[i] > array[i/2]; i /= 2){
        comparacao++;
        swap(array + i, array + i/2);
        trocas++;
    }
}
//=============================================================================
int getMaiorFilho(int *array, int i, int tamHeap){
    int filho;
    comparacao++;
    if (2*i == tamHeap || array[2*i] > array[2*i+1]){
        filho = 2*i;
    } else {
        filho = 2*i + 1;
    }
    return filho;
}
//=============================================================================
void reconstroi(int *array, int tamHeap){
    int i = 1;
    while(i <= (tamHeap/2)){
        int filho = getMaiorFilho(array, i, tamHeap);
        comparacao++;
        if(array[i] < array[filho]){
            swap(array + i, array + filho);
            trocas++;
            i = filho;
        }else{
            i = tamHeap;
        }
    }
}
//=============================================================================
void heapsort(int *array, int n) {
    
    comparacao = 0;
    trocas = 0;
    
    //Alterar o vetor ignorando a posicao zero
    int *arrayTmp = (int*) malloc(n+1 * sizeof(int));
    
    for(int i = 0; i < n; i++){
        arrayTmp[i+1] = array[i];
    }

    //Contrucao do heap
    for(int tamHeap = 2; tamHeap <= n; tamHeap++){
        constroi(arrayTmp, tamHeap);
    }

    //Ordenacao propriamente dita
    int tamHeap = n;
    while(tamHeap > 1){
        swap(arrayTmp + 1, arrayTmp + tamHeap--);
        trocas++;
        reconstroi(arrayTmp, tamHeap);
    }

    //Alterar o vetor para voltar a posicao zero
    for(int i = 0; i < n; i++){
        array[i] = arrayTmp[i+1];
        trocas++;
    }

    printf("\t%d", comparacao);
    printf("\t%d", trocas);
}
//=============================================================================