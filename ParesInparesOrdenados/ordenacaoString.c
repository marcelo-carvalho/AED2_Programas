#include <stdio.h>
#include <string.h>

struct Entradas {
    char frase[50];
    int tamanho;
};

int separaPalavras(char *frase, struct Entradas *palavras);
void insercao(struct Entradas *array, int n);
void zeraVetor(struct Entradas *array);

int main(){
    struct Entradas entrada[50];
    char palavra[10000];
    int contador_string = 0;
    int n;

    scanf("%d\n",&n);
    zeraVetor(entrada);

    for(int i = 0; i < n; i++){
        
        fgets(palavra, sizeof palavra, stdin);
        
        for(int i=0; i <= strlen(palavra); i++ ){
            if(palavra[i] == '\n'){
                palavra[i-1] = '\0';
            }
        }
            
        contador_string = separaPalavras(palavra,entrada);
        insercao(entrada,contador_string);

        for(int i = 0; i < contador_string; i++){
            printf("%s ", entrada[i].frase);
        }
        printf("\n");
        contador_string = 0;
    }

    return 0;
}

int separaPalavras(char *frase, struct Entradas *palavras){
    int i, j, ctr;
    j=0; ctr=0;
    for(i = 0; i <= strlen(frase); i++){
        if(frase[i] == ' ' || frase[i] == '\0' || frase[i] == '\n'){
            palavras[ctr].frase[j] = '\0';
            ctr++;
            j=0;
        }
        else{
            palavras[ctr].frase[j] = frase[i];
            palavras[ctr].tamanho++;
            j++;
        }
    }
    return ctr;
}

void insercao(struct Entradas *array, int n){
    struct Entradas tmp;
    int i, j;
    
    for (i = 1; i < n; i++) {
      j = i;
      while ((j > 0) && (array[j].tamanho > array[j-1].tamanho) ) {
        tmp = array[j];
        array[j] = array[j - 1];
        array[j-1] = tmp;
        j--;
      }
   }
}

void zeraVetor(struct Entradas *array){
    for(int i = 0; i < 50; i++){
        array[i].frase[0] = '\0';
        array[i].tamanho = 0;
    }
}

/*void insercao(struct Entradas *array, int n){
    for (int i = 1; i < n-1; i++) {
      struct Entradas tmp = array[i];
      int j = i - 1;

      while ((j >= 0) && (array[j].tamanho < tmp.tamanho)) {
         array[j + 1] = array[j];
         j--;
      }
      array[j+1] = tmp;
   }
}*/