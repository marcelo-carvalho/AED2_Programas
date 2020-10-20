import java.util.Scanner;

public class Palindromos{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String linha, linhaInversa;

        linha = sc.nextLine();

        while(linha.compareTo("FIM") != 0){
            linhaInversa = new StringBuilder(linha).reverse().toString();

            if(linha.compareTo(linhaInversa) == 0)
                System.out.printf("SIM\n");
            else 
                System.out.printf("NAO\n");
            
            linha = sc.nextLine();
        }
        
        sc.close();
    }
}