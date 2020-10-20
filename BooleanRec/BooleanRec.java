import java.util.Scanner;

public class BooleanRec {
    
    //Para remover os espaços
    public static String removeEspaco(String frase){
        StringBuilder nFrase = new StringBuilder();
        int i=0, j=0, tam;
        tam = frase.length();
    
        for(i = 0; i < tam; i++){
            if(frase.charAt(i) == ' '){
                continue;
            }
            nFrase.append(frase.charAt(i));
        }
        return nFrase.toString();
    }

    //Função recurisiva 
    public static boolean resolveExpressao(int args[], String expression) {
        int i = 0, index_substring = 0;
        boolean resultado = false;
        StringBuilder operacao = new StringBuilder();
        StringBuilder[] argumentos = new StringBuilder[10];
        int contador_argumentos = 0;
        int contador_parenteses = 0;
    
        //Condição de parada da recurção.
        if(expression.charAt(0) >= 'A' && expression.charAt(0) <= 'Z'){    
            return args[expression.charAt(0) - 65 ] == 1;
        }
        
        while(i < expression.length()){
            //encontra uma operação.
            if(expression.charAt(i) == '(') {
                //Encontra um contexto de operação.
                contador_parenteses++;
                if (contador_parenteses == 1) {
                    //copia a operação para a string.
                    for(index_substring = 0; index_substring < i; index_substring++){
                        operacao.append(expression.charAt(index_substring));
                    }
                }
            }
            if(expression.charAt(i) == ')'){
                //Termina um contexto de operação.
                if(contador_parenteses == 1){
                    index_substring++; // pula o ")" na string de entrada.
                    argumentos[contador_argumentos] = new StringBuilder();
                    for(; index_substring < i; index_substring++){
                        argumentos[contador_argumentos].append(expression.charAt(index_substring));
                    }
                    contador_argumentos++;
                }
                contador_parenteses--;
                
            }
            if(expression.charAt(i) == ',' && contador_parenteses == 1){
                index_substring++; // pula o "," na string de entrada.
                argumentos[contador_argumentos] = new StringBuilder();
                for(; index_substring < i; index_substring++){
                    argumentos[contador_argumentos].append(expression.charAt(index_substring));
                }
                contador_argumentos++; 
            }
            i++;
        }

        switch(operacao.charAt(0)){
            case 'n'://NOT
                return !resolveExpressao(args, argumentos[0].toString());
    
            case 'a'://AND
                resultado = true;
                for(int b = 0; b < contador_argumentos; b++){
                    resultado = resultado && resolveExpressao(args, argumentos[b].toString());
                }
                break;
            case 'o'://OR
                resultado = false;
                for(int b = 0; b < contador_argumentos; b++){
                    resultado = resultado | resolveExpressao(args, argumentos[b].toString());
                }
                break;
        }
        return resultado;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int[] argumentos = new int[27];
        int num_arg;
        String expression;
        
        //procedimento para leitura da string de entrada.
        num_arg = sc.nextInt();
    
        while(num_arg != 0){
            for(int i = 0; i < num_arg; i++){
                argumentos[i] = sc.nextInt();
            }
            expression = sc.nextLine();
            //Fim da leitura
    
            expression = removeEspaco(expression);
            System.out.printf(resolveExpressao(argumentos, expression) ? "SIM\n" : "NAO\n");
            num_arg = sc.nextInt();
        }
        sc.close();
    }
}