import java.util.Scanner;

public class OrdenacaoParcial{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n;
        int k;
        int[] vetor;
        int contador = 0;

        n = sc.nextInt();
        vetor = new int[n];

        k = sc.nextInt();

        for(int i = 0; i < n ; i++){
            vetor[i] = sc.nextInt();
        }

        for(int i = 1; i < n; i++){
            int temp = vetor[i];
            int j = i - 1;
            
            while((j>=0) && (vetor[j] < temp)){
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = temp;
        }

        int maior = vetor[0];

        for(int i = 0; i < n; i++){
            if(contador < k || vetor[i] == maior){
                if(vetor[i] == maior){
                    maior = vetor[i];
                    contador++;
                }
                else{
                    maior = vetor[i];
                    contador++;
                }
            }
        }

        System.out.printf("%d", contador);
        sc.close();
    }
}