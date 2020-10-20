#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeEnter(char* frase);
void removeEspaco(char* frase);
int resolveExpressao(int args[], char expression[]) ;

int main(void) {
    int args[50];
    int num_arg;
    char expression[300];
    
    //procedimento para leitura da string de entrada.
    scanf("%d",&num_arg);

    while(num_arg != 0){
        for(int i = 0; i < num_arg; i++){
            scanf("%d",&args[i]);
        }
        fgets(expression,sizeof(expression),stdin);
        //Fim da leitura

        removeEspaco(expression);
        removeEnter(expression);
        printf(resolveExpressao(args, expression) ? "SIM\n" : "NAO\n");
        scanf("%d",&num_arg);
    }

    return 0;
}

//Para remover o enter
void removeEnter(char* frase){
    int tam = strlen(frase);
    for(int i=0; i < tam; i++){
        if(frase[i] == '\n')
            frase[i] = '\0';
    }
}

//Para remover os espaços
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


int resolveExpressao(int args[], char expression[]) {
    int i = 0, index_substring = 0, a=0, resultado;
    char operacao[4];
    char argumentos[10][100];
    int contador_argumentos = 0;
    int contador_parenteses = 0;

    //Condição de parada da recurção.
    if(expression[0] >= 'A' && expression[0] <= 'Z'){    
        return args[expression[0] - 65 ];
    }
    
    while(expression[i] != '\0'){
        
        //encontra uma operação.
        if(expression[i] == '(') {
            //Encontra um contexto de operação.
            contador_parenteses++;
            if (contador_parenteses == 1) {
                //copia a opera????o para a string.
                for(index_substring = 0; index_substring < i; index_substring++){
                    operacao[index_substring] = expression[index_substring];
                }
                operacao[index_substring] = '\0';
            }
        }
        if(expression[i] == ')'){
            //Termina um contexto de operação.
            if(contador_parenteses == 1){
                index_substring++; // pula o ")" na string de entrada.
                for(a = 0; index_substring < i; index_substring++,a++){
                    argumentos[contador_argumentos][a] = expression[index_substring];
                }
                argumentos[contador_argumentos][a] = '\0';
                contador_argumentos++;
            }
            contador_parenteses--;
            
        }
        if(expression[i] == ',' && contador_parenteses == 1){
            //a ?? uma variável auxiliar para copiar a substring
            index_substring++; // pula o "," na string de entrada.
            for(a = 0; index_substring < i; index_substring++,a++){
                argumentos[contador_argumentos][a] = expression[index_substring];
            }
            argumentos[contador_argumentos][a] = '\0';
            contador_argumentos++; 
        }
        
        i++;
    }

    switch(operacao[0]){
        
        case 'n'://NOT
            return !resolveExpressao(args, argumentos[0]);
            break;

        case 'a'://AND
            resultado = 1;
            for(int b = 0; b < contador_argumentos; b++){
                resultado = resultado && resolveExpressao(args, argumentos[b]);
            }
            break;
        case 'o'://OR
            resultado = 0;
            for(int b = 0; b < contador_argumentos; b++){
                resultado = resultado || resolveExpressao(args, argumentos[b]);
            }
            break;
    }
    
    return resultado;
}

