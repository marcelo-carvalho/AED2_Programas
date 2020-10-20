#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define NOT 2
#define AND 3
#define OR 4

void removeEnter(char* frase);
void removeEspaco(char* frase);
int resolveExpressao(int args[], char expression[]) ;
void resolverOperacao(int pilha[], int *prox_pilha, int end_operacao);
int eOperacao(int operacao);
void executarOperacao(int pilha[], int* prox_pilha);

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


int resolveExpressao(int args[], char expression[]) {
    int pilha[100];
    int prox_pilha =0, i=0;


    //varre toda a string.
    while(expression[i] != '\0'){
        if(expression[i] == 'a'){
            pilha[prox_pilha] = AND;
            prox_pilha++;
            // pula 'and('
            i = i + 4;
        }
        else if(expression[i] == 'o'){
            pilha[prox_pilha] = OR;
            prox_pilha++;
            // pula 'or('
            i = i + 3;
        }
        else if(expression[i] == 'n'){
            pilha[prox_pilha] = NOT;
            prox_pilha++;
            // pula 'not('
            i = i + 4;
        }
        else if(expression[i] >= 'A' && expression[i] <= 'Z'){
            //Subtraindo ASCII A (dec 65) 
            pilha[prox_pilha] = args[expression[i] - 65 ];
            prox_pilha++;
            // pula 'not('
            i = i + 1;
        }
         else if(expression[i] == ')'){
            //?? um fecha parenteses ent??o tem uma opera????o a ser resolvida.
            executarOperacao(pilha,&prox_pilha);
            i++;
        }
        else {
            //caracteres ignorados. 
            i++;
        }
    }
    return pilha[0];
}

void executarOperacao(int pilha[], int* prox_pilha){
    //procurar pela primeira opera????o 
    int operacao = *prox_pilha - 1;
    while(!eOperacao(pilha[operacao])){
        operacao--;
    }
    resolverOperacao(pilha,prox_pilha,operacao);
}

//Identifica se o valor equivale a uma operacao ou n??o.
int eOperacao(int operacao){
    return operacao == OR || operacao == AND || operacao == NOT; 
}

//Faz a leitura da string e identifica cada opera????o e as executa quando ocorre ")".
void resolverOperacao(int pilha[], int *prox_pilha, int end_operacao){
    int guarda_valor;
    int guarda_end_operacao = end_operacao;
    
    switch(pilha[end_operacao]){
        case NOT:
            //O argumento est?? acima do valor da guarda_opera????o
            pilha[guarda_end_operacao] = !(pilha[guarda_end_operacao + 1]);
            *prox_pilha = guarda_end_operacao + 1;
            break;
        case AND:
            //navega????o na pilha utilizando opera????o
            end_operacao = end_operacao + 1;
            guarda_valor = pilha[end_operacao];
            end_operacao = end_operacao + 1;
            
            //Buscando proximo argumento para executar o AND
            while(end_operacao != *prox_pilha){
                guarda_valor = pilha[end_operacao] && guarda_valor;
                end_operacao = end_operacao + 1;
            }
            pilha[guarda_end_operacao] = guarda_valor;
            *prox_pilha = guarda_end_operacao + 1;
            break;
        case OR:
            //navega????o na pilha utilizando opera????o
            end_operacao = end_operacao + 1;
            guarda_valor = pilha[end_operacao];
            end_operacao = end_operacao + 1;
            
            //Buscando proximo argumento para executar o OR
            while(end_operacao != *prox_pilha){
                guarda_valor = pilha[end_operacao] || guarda_valor;
                end_operacao = end_operacao + 1;
            }
            pilha[guarda_end_operacao] = guarda_valor;
            *prox_pilha = guarda_end_operacao + 1;
            break;
    }
}