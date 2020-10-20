import java.util.Scanner;

public class MenorValor{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int vetor[];
        int n, posicao = 0, menor = 10000;

        n = sc.nextInt();
        vetor = new int[n];

        for(int i =0; i < n; i++){
            vetor[i] = sc.nextInt();
            
            if(vetor[i] < menor){
                menor = vetor[i];
                posicao = i;
            }
        }

        System.out.printf("Menor valor: %d\n",menor);
        System.out.printf("Posicao: %d\n",posicao);
        
        sc.close();
    }
}