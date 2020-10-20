#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Para remover os espa??os
void removeEspaco(char* frase){
  int i=0, j=0, tam;
  tam = strlen(frase);

  for(i = 0; i < tam; i++){
    if(frase[i] == ' '){
      continue;
    }
    frase[j] = frase[i];
    j++;
  }
  frase[j] = '\0';
}

//M??todo para transformar todas as letras e minusculas 
void minuscula(char* frase){
  int i, tam;
  tam = strlen(frase) - 1;

  for(i =0; i < tam; i++){
    if(frase[i] > 40 && frase[i] < 91){
     frase[i] = tolower(frase[i]);
    }
  }
}

int ePalidondromo(char* frase, int n){
    if(n == 0 || n == 1){
        return 1;
    }
    if(frase[0] != frase[n-1]){
        return 0;
    }
    return ePalidondromo(&frase[1], n -2);
}

void tiraEnter(char* frase){
    int tam = strlen(frase);
    for(int i=0; i < tam; i++){
        if(frase[i] == '\n')
        frase[i] = '\0';
    }
}


int main(void) {
  char frase[128];
  char FIM[] = "FIM";
  int i=0, j=0, tam;

 fgets(frase,sizeof(frase), stdin);

  while(strcmp(frase,FIM) != 0){
    
    tiraEnter(frase);
    removeEspaco(frase);
    minuscula(frase);
    tam = strlen(frase);
    
    if(ePalidondromo(frase,tam-1) == 1) 
        printf("SIM\n");
    else 
        printf("NAO\n");

    fgets(frase,sizeof(frase), stdin);
    
  }

  return 0;
}