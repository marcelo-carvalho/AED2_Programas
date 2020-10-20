import java.util.Scanner;

public class Boolean{

    public static int FALSE = 0;
    public static int TRUE = 1;
    public static int NOT = 2;
    public static int AND = 3;
    public static int OR = 4; 

    //Para remover os espaços
    static String removeEspaco(String frase){
        StringBuilder nFrase = new StringBuilder();
        int i, tam = 0;
        tam = frase.length();
    
        for(i = 0; i < tam; i++){
            if(frase.charAt(i) == ' '){
                continue;
            }
            nFrase.append(frase.charAt(i));
        }
        return nFrase.toString();
    }

    static int resolveExpressao(int args[], String expression) {
        int[] pilha = new int[100];
        int prox_pilha =0, i=0;
    
        //varre toda a string de entrada para iniciar a separação das operações.
        while(i < expression.length()){
            if(expression.charAt(i) == 'a'){
                pilha[prox_pilha] = AND;
                prox_pilha++;
                // pula 'and('
                i = i + 4;
            }
            else if(expression.charAt(i) == 'o'){
                pilha[prox_pilha] = OR;
                prox_pilha++;
                // pula 'or('
                i = i + 3;
            }
            else if(expression.charAt(i) == 'n'){
                pilha[prox_pilha] = NOT;
                prox_pilha++;
                // pula 'not('
                i = i + 4;
            }
            else if(expression.charAt(i) >= 'A' && expression.charAt(i) <= 'Z'){
                //Subtraindo ASCII A (dec 65) para ter um valor entre 0 e 27
                pilha[prox_pilha] = (int) args[expression.charAt(i) - 65 ];
                prox_pilha++;
                // pula 'not('
                i = i + 1;
            }
             else if(expression.charAt(i) == ')'){
                //É um fecha parenteses então tem uma operação a ser resolvida.
                prox_pilha = executarOperacao(pilha,prox_pilha);
                i++;
            }
            else {
                //caracteres ignorados. 
                i++;
            }
        }
        return pilha[0];
    }

    //Faz a leitura da string e identifica cada opera????o e as executa quando ocorre ")".
    static int resolverOperacao(int pilha[], int prox_pilha, int end_operacao){
        int guarda_valor;
        int guarda_end_operacao = end_operacao;
        
        switch(pilha[end_operacao]){
            case 2: //NOT
                //O argumento está acima do valor da guarda_operação
                pilha[guarda_end_operacao] = (pilha[guarda_end_operacao + 1] == 1 ? FALSE : TRUE);
                prox_pilha = guarda_end_operacao + 1;
                break;
            case 3: //AND
                //navegando na pilha utilizando operação
                end_operacao = end_operacao + 1;
                guarda_valor = pilha[end_operacao];
                end_operacao = end_operacao + 1;
                
                //Buscando proximo argumento para executar o AND
                while(end_operacao != prox_pilha){
                    guarda_valor = pilha[end_operacao] & guarda_valor;
                    end_operacao = end_operacao + 1;
                }
                pilha[guarda_end_operacao] = guarda_valor;
                prox_pilha = guarda_end_operacao + 1;
                break;
            case 4: //OR
                //navegando na pilha utilizando operação
                end_operacao = end_operacao + 1;
                guarda_valor = pilha[end_operacao];
                end_operacao = end_operacao + 1;
                
                //Buscando proximo argumento para executar o OR
                while(end_operacao != prox_pilha){
                    guarda_valor = pilha[end_operacao] | guarda_valor;
                    end_operacao = end_operacao + 1;
                }
                pilha[guarda_end_operacao] = guarda_valor;
                prox_pilha = guarda_end_operacao + 1;
                break;
        }
        return prox_pilha;
    }

    //Identifica se o valor equivale a uma operacao ou n??o.
    static boolean eOperacao(int operacao){
        return operacao == OR || operacao == AND || operacao == NOT; 
    }

    static int executarOperacao(int pilha[], int prox_pilha){
        //procurar pela primeira opera????o 
        int operacao = prox_pilha - 1;
        while(!eOperacao(pilha[operacao])){
            operacao--;
        }
        return resolverOperacao(pilha,prox_pilha,operacao);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int[] argumentos = new int[50];
        String expression = new String();
        int num_arg;
        
        //procedimento para leitura da string de entrada.
        num_arg = sc.nextInt();
    
        while(num_arg != 0){
            for(int i = 0; i < num_arg; i++){
                argumentos[i] = sc.nextInt();
            }
            expression = sc.nextLine();
            //Fim da leitura
    
            expression = removeEspaco(expression);
            System.out.printf(resolveExpressao(argumentos, expression) == TRUE ? "SIM\n" : "NAO\n");
            num_arg = sc.nextInt();
        }
        sc.close();
    }
}