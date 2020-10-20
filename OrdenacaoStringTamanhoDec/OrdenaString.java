import java.util.Scanner;

public class OrdenaString{

    //função para separar as palavras da string de entrada.
    public static int separaPalavra(String entrada, String[] palavras){
        StringBuilder aux = new StringBuilder();
        int cnt = 0;
        int i = 0;
        int n = entrada.length();
        
        do{
            
            if(entrada.charAt(i) == ' '){
                palavras[cnt] = aux.toString();
                aux.delete(0, aux.length());
                cnt++;
            }
            else{
                aux.append(entrada.charAt(i));
            }
            i++;
        }while(i < n);
        palavras[cnt] = aux.toString();
        cnt++;
        return cnt;
    }


    //algoratimo de ordenação modifciado para ordem decrescente
    public static void insercao(String[] array, int n){ 
        String tmp;
        int i, j;
        
        for (i = 1; i < n; i++) {
            j = i;
            while ((j > 0) && (array[j].length() > array[j-1].length()) ) {
                    tmp = array[j];
                    array[j] = array[j - 1];
                    array[j-1] = tmp;
                j--;
            }
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n, cnt_string;
        String entrada;
        String[] palavras = new String[50];

        n = sc.nextInt();
        sc.nextLine();
        for(int i = 0; i < n; i++){
            entrada = sc.nextLine();
            cnt_string = separaPalavra(entrada, palavras);
            insercao(palavras, cnt_string);
            
            for(int j = 0; j < cnt_string; j++){
                System.out.printf("%s ", palavras[j]);
            }
            System.out.printf("\n");
        }
        
        sc.close();
    }
}