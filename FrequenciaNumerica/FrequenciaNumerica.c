#include <stdio.h>

int main(){
    int vetor[2000];
    int n, aux;
        
        //Preenche todas as posições do vetor com zero
        for(int i = 0; i < 2000; i ++)
            vetor[i] = 0;
        
        scanf("%d",&n); 

        //o valor informado é usado como indice do vetor e incrimenta-se o valor indicado pelo indice.
        for(int i = 0; i < n; i++){
            scanf("%d",&aux);
            vetor[aux]++;
        }

        //Imprime apenas os vetores que possuem valor diferente de zero.  
        for(int i = 0; i < 2000; i++){
            if(vetor[i] != 0){
                printf("%d aparece %d vez(es)\n",i,vetor[i]);
            }
        }
    
    return 0;
}