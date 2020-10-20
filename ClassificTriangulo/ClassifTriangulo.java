import java.util.Scanner;

public class ClassifTriangulo{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a, b, c, soma;

        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        soma = a + b + c;

        if(a > soma /2 || b > soma /2 || c > soma /2){
            System.out.printf("NAO FORMA UM TRIANGULO\n");
        }
        else if(a == b){
           if(b == c){
            System.out.printf("EQUILATERO\n");
           }
           else {
            System.out.printf("ISOSCELES\n");
           }
        }
        else if (b == c){
            if(a == c){
                System.out.printf("EQUILATERO\n");
           }
           else {
            System.out.printf("ISOSCELES\n");
           }
        }
        else if (a == c){
            if(b == c){
                System.out.printf("EQUILATERO\n");
           }
           else {
            System.out.printf("ISOSCELES\n");
           }
        }
        else if(a != b && a != c && b != c){
            System.out.printf("ESCALENO\n");
        }

        sc.close();
    }
}