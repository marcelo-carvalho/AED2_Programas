#include <stdio.h>

int main(){
    int vetor[1000];
    int n, aux, posicao = 0, menor = 10000;

    scanf("%d",&n);

    for(int i =0; i < n; i++){
        scanf("%d",&aux);
        vetor[i] = aux;
        
        if(vetor[i] < menor){
            menor = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n",menor);
    printf("Posicao: %d\n",posicao);
    
    return 0;
}