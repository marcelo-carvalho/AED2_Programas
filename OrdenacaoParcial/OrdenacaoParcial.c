#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int k;
    int *vetor;
    int contador = 0;

    scanf("%d", &n);
    vetor = (int*) malloc(n * sizeof(int));
    scanf("%d", &k);

    for(int i = 0; i < n ; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 1; i < n; i++){
        int temp = vetor[i];
        int j = i - 1;
        
        while((j>=0) && (vetor[j] < temp)){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = temp;
    }

    int maior = vetor[0];

    for(int i = 0; i < n; i++){
        if(contador < k || vetor[i] == maior){
            if(vetor[i] == maior){
                maior = vetor[i];
                contador++;
            }
            else{
                maior = vetor[i];
                contador++;
            }
        }
    }

    printf("%d", contador);
    return 0;
}