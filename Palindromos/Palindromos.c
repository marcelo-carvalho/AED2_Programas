#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Para remover os espa??os
void removeEspaco(char* frase){
  char fraseNormal[128];
  char fraseInversa[128];
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

//M??todo para criar a string invertida
void inverteFrase(char* frase, char* inversa){
  int i=0, j=0, tam;
  tam = strlen(frase);

  for(i = tam -3,j = 0; i >= 0; i--,j++ ){
      
    inversa[j] = frase[i];
  }
  inversa[j] = '\0';
}

//M??todo para transformar todas as letras e minusculas 
void minuscula(char* frase){
  int i, tam;
  tam = strlen(frase);

  for(i =0; i < tam; i++){
    if(frase[i] > 40 && frase[i] < 91){
     frase[i] = tolower(frase[i]);
    }
  }
}

int main(void) {
  char fraseNormal[128];
  char fraseInversa[128];
  char FIM[] = "FIM";
  int i=0, j=0, tam, flag = 0;

  //gets(fraseNormal);
  fgets(fraseNormal,sizeof(fraseNormal), stdin);
  
  while(strcmp(fraseNormal,FIM) != 0){
    removeEspaco(fraseNormal); //Remove os espa??os da String
    minuscula(fraseNormal); //Passa todas as letras para min??sculas
    tam = strlen(fraseNormal);
    inverteFrase(fraseNormal,fraseInversa); //Gera a string inversa
      
      for(i=0; i < tam-2; i++){
        if(fraseInversa[i] == fraseNormal[i]){
          flag = 1;
          //printf("S[%d] %c %c\n", i, fraseInversa[i], fraseNormal[i]);
        }
        else{
          flag = 0;
          //printf("N[%d] %c %c\n", i, fraseInversa[i], fraseNormal[i]);
          break;
        }
      }
      if(flag == 1) printf("SIM\n");
      else printf("NAO\n");
    
    fgets(fraseNormal,sizeof(fraseNormal), stdin);
  }

  return 0;
}