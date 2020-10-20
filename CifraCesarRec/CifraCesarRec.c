#include <stdio.h>
#include <string.h>

void encriptar(char[], char[],  int);

int main(){
    char fraseNormal[128]; 
    char fraseCifrada[128];

    scanf("%[^\n]s",fraseNormal);
    scanf("%*c");

    while(strcmp(fraseNormal,"FIM") != 0){ //loop interrompe ao identificar a string FIM
        encriptar(fraseNormal,fraseCifrada,0);
        printf("%s\n", fraseCifrada);
        scanf("%[^\n]s",fraseNormal);
        scanf("%*c");
    }

    return 0;
}

void encriptar(char fraseNormal[128], char fraseEncriptada[128], int n){
    int chave = 3; //valor da cifra
            
        if(fraseNormal[n] == '\0'){
            fraseEncriptada[n] = '\0';
            return;
        }
        else if(fraseNormal[n] < 91 && fraseNormal[n] > 64){ //Condição para letras maisuculas
            fraseEncriptada[n] = (fraseNormal[n] + chave - 65) % 26 + 65;
            encriptar(fraseNormal, fraseEncriptada, n + 1);
        }
        else if(fraseNormal[n] == ' '){ //condição para espaço
            fraseEncriptada[n] = ' ';
            encriptar(fraseNormal, fraseEncriptada, n + 1);
        }
        else { //condição para letras minusculas
            fraseEncriptada[n] = (fraseNormal[n] + chave - 97) % 26 + 97;
            encriptar(fraseNormal, fraseEncriptada, n + 1);
        }
}