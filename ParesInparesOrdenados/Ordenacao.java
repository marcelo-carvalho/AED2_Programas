import java.util.Scanner;

public class Ordenacao{
    
    public static void insercao(int[] array, int n) {
		for (int i = 1; i < n; i++) {
			int tmp = array[i];
         int j = i - 1;

         while ((j >= 0) && (array[j] > tmp)) {
            array[j + 1] = array[j];
            j--;
         }
         array[j + 1] = tmp;
      } 
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int[] par = new int[105];
        int[] impar = new int[105];
        int n, entrada;
        int contador_par = 0;
        int contador_impar = 0;

        n = sc.nextInt();
        if(n > 0 && n < 105){
            for(int i=0; i < n; i++){
                entrada = sc.nextInt();
                if(entrada >= 0 ){
                    if(entrada % 2 == 0){
                        par[contador_par] = entrada;
                        contador_par++;
                    }
                    else{
                        impar[contador_impar] = entrada;
                        contador_impar++;
                    }
                }
            }
    
            insercao(par,contador_par);
            insercao(impar,contador_impar);
            
            for(int i =0; i < contador_par; i++) {
                System.out.printf("%d\n",par[i]);
            }
                
            for(int i = contador_impar -1 ; i >= 0; i-- ) {
                System.out.printf("%d\n",impar[i]);
            }
        }

        sc.close();
    }
}