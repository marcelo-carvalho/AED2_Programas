#include <stdio.h>
#include <string.h>
#include <ctype.h>


void minuscula(char* frase){
  int i, tam;
  tam = strlen(frase);

  for(i =0; i < tam-1; i++){
    if(frase[i] > 40 && frase[i] < 91){
     frase[i] = tolower(frase[i]);
    }
  }
}

int maior(int *vetor){
  int maior = 0;
  
  for(int i = 0; i < 255; i++){
    if(maior < vetor[i]){
      maior = vetor[i];
    }
  }
  return maior;
}

void imprime(int *vetor, int maior){
  for(int i = 32; i < 128; i ++){
    if(vetor[i] == maior ){
      printf("%c",(char) i);
    }
  }
  printf("\n");
}

void limpaVetor(int *vetor){
  for(int i = 0; i < 255; i++){
    vetor[i] = 0;
  }
}

int main(void) {
  int caracter[255];
  char frase[200];
  int tam, n, maiorFreq;

  scanf("%d\n",&n);
  setbuf(stdin, NULL);

  while(n > 0){
    fgets(frase,sizeof(frase),stdin);
    minuscula(frase);
    tam = strlen(frase);
    limpaVetor(caracter);
    
    for(int i = 0; i < tam -1; i++){
      if(frase[i] != ' ')
        caracter[(int)frase[i]]++;
    }

    maiorFreq = maior(caracter);
    imprime(caracter, maiorFreq);
    n--;
  }

  return 0;
}