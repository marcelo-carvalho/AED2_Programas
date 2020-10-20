#include <stdio.h>
#include <stdlib.h>

char* somenteConsoante(char *v, int n);
int eVogal(char c);

int main(){
    char *frase = (char *) malloc(50);
    char *saida = (char *) malloc(50);
    
    scanf("%[^\n]s", frase);
    printf("%s\n", frase);
    saida = somenteConsoante(frase, sizeof(frase) / sizeof(char));
    printf("%s", saida);

    free(frase);
    return 0;
}

char* somenteConsoante(char *v, int n){
    char *saida = (char *) malloc(n);
    int k = 0;
    for(int i = 0; i < n; i++){
        if(eVogal(v[i]) == 0){
            saida[k] = v[i];
            k++;
        }
    }
    saida[k] = '\0';
    return saida;
}

int eVogal(char c){
    if(c=='A' || c=='a' ||
        c=='E' || c=='e' ||
        c=='I' || c=='i' ||
        c=='O' || c=='o' ||
        c=='U' || c=='u'){
            return 1;
    }
    else{
        return 0;
    }
}