#include <stdio.h>
#include <string.h>

void encriptar(char[], char[]);

int main(){
    char fraseNormal[128]; 
    char fraseCifrada[128];

    scanf("%[^\n]s",fraseNormal);
    scanf("%*c");

    while(strcmp(fraseNormal,"FIM") != 0){ //loop interrompe ao identificar a string FIM
        encriptar(fraseNormal,fraseCifrada);
        printf("%s\n", fraseCifrada);
        scanf("%[^\n]s",fraseNormal);
        scanf("%*c");
    }

    return 0;
}

void encriptar(char fraseNormal[128], char fraseEncriptada[128]){
    int chave = 3; //valor da cibra
    int contador = 0;

    for(int i =0; fraseNormal[i] != '\0'; i++){ ///Loop executa até encontrar o '\0'
        
        if(fraseNormal[i] < 91 && fraseNormal[i] > 64){ //Condição para letras maisuculas
            fraseEncriptada[i] = (fraseNormal[i] + chave - 65) % 26 + 65;
            contador++;
        }
        else if(fraseNormal[i] == ' '){ //condição para espaço
            fraseEncriptada[i] = ' ';
            contador++;
        }
        else { //condição para letras minusculas
            fraseEncriptada[i] = (fraseNormal[i] + chave - 97) % 26 + 97;
            contador++;
        }
    }

    fraseEncriptada[contador] = '\0'; //adiciona o '\0' ao final de fraseEncriptada.
}