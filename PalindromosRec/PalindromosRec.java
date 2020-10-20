import java.util.Scanner;

public class PalindromosRec {

    public static String removeEspaco(String frase){
        StringBuilder nFrase = new StringBuilder();
        int i=0, tam;
        tam = frase.length();
    
        for(i = 0; i < tam; i++){
          if(frase.charAt(i) == ' '){
            continue;
          }
          nFrase.append(frase.toLowerCase().charAt(i));
        }
        return nFrase.toString();
    }


    static boolean ePalidondromo(String frase, int n){
        if(n == 0 || n == 1){
            return true;
        }
        if(frase.charAt(0) != frase.charAt(n-1)){
            return false;
        }
        return ePalidondromo(frase.substring(1,n-1), n -2);
    }


    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        String frase;
        int tam;

        frase = sc.nextLine();

        while(!frase.equals("FIM")){
            
            frase = removeEspaco(frase);
            frase.toLowerCase();
            tam = frase.length();
            
            if(ePalidondromo(frase,tam)) 
                System.out.printf("SIM\n");
            else 
                System.out.printf("NAO\n");

            frase = sc.nextLine();
        }
        sc.close();
    }
}