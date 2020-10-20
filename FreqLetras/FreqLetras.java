import java.util.Scanner;

public class FreqLetras {
      
     static int maior(int[] vetor){
        int maior = 0;
        
        for(int i = 0; i < 123; i++){
          if(maior < vetor[i]){
            maior = vetor[i];
          }
        }
        return maior;
      }
      
      static void imprime(int[] vetor, int maior){
        for(int i = 0; i < 123; i ++){
          if(vetor[i] == maior && vetor[i] != 0){
            System.out.printf("%c",(char) i);
          }
        }
        System.out.printf("\n");
      }
      
      static int[] limpaVetor(int[] vetor){
        for(int i = 0; i < 123; i++){
          vetor[i] = 0;
        }
        return vetor;
      }
      
      public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int[] caracter = new int[123];
        String frase = new String();
        int tam, n, maiorFreq;
      
        n = sc.nextInt();
        sc.nextLine();
        while(n > 0){
          frase = sc.nextLine();
          frase = frase.toLowerCase();
          tam = frase.length();
          caracter = limpaVetor(caracter);
          
          for(int i = 0; i < tam ; i++){
            if(frase.charAt(i) != ' ')
              caracter[(int)frase.charAt(i)]++;
          }
      
          maiorFreq = maior(caracter);
          imprime(caracter, maiorFreq);
          n--;
        }
        sc.close();
      }
}