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

    for(int i = 0; i < n; i++){
        
        zeraVetor(entrada); //Zera o vetor de struc
        fgets(palavra, sizeof(palavra), stdin); //lê a string do console

        for(int i=0; i <= strlen(palavra); i++ ){ //elimina o enter
            if(palavra[i] == '\n'){
                palavra[i-1] = '\0';
                //palavra[i-1] = '\0'; //Eureka faz contagem diferente.
            }
        }

        contador_string = separaPalavras(palavra,entrada); //Separa as palavras
        insercao(entrada,contador_string); //ordena as palavras por tamanho

        for(int i = 0; i < contador_string; i++){ //imprime as palavras a tela
            printf("%s ", entrada[i].frase);
        }
        printf("\n");
        contador_string = 0;
    }

    return 0;
}

//metódo para separar as palavras da string de entrada
int separaPalavras(char *frase, struct Entradas *palavras){
    int i, j, ctr;
    j=0; ctr=0;
    for(i = 0; i <= strlen(frase); i++){
        if(frase[i] == ' ' || frase[i] == '\0' || frase[i] == '\n'){ //determina o fim da plavra
            palavras[ctr].frase[j] = '\0';
            ctr++;
            j=0;
        }
        else{ //considera o caracter ainda parte de uma palavra
            palavras[ctr].frase[j] = frase[i];
            palavras[ctr].tamanho++;
            j++;
        }
    }
    return ctr; //retorna a quantidade de palavras encontradas
}

//algoratimo de ordenação modifciado para ordem decrescente
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

//algorimto para zerar o vetor
void zeraVetor(struct Entradas *array){ 
    for(int i = 0; i < 50; i++){
        array[i].frase[0] = '\0';
        array[i].tamanho = 0;
    }
}
