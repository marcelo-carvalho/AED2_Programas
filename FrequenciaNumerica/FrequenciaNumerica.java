import java.util.Scanner;

public class FrequenciaNumerica{
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int vetor[] = new int[2000];
        int n;

        for(int i = 0; i < 2000; i ++)
            vetor[i] = -1;
        
        n = sc.nextInt();

        for(int i = 0; i < n; i++)
            vetor[sc.nextInt()]++;
            
        for(int i = 0; i < 2000; i++){
            if(vetor[i] != -1){
                System.out.printf("%d aparece %d vez(es)\n",i,vetor[i]+1);
            }
        }

        sc.close();
    }
}