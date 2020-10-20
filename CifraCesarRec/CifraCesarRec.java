import java.util.Scanner;

public class CifraCesarRec{
   
    public static void encriptar(String texto, StringBuilder textoCifrado, int n) {
        int chave = 3; // determina o valor do deslocamento das letras
        char ch;
            
            if(n == texto.length()){
                return;
            }
            else if (Character.isUpperCase(texto.charAt(n))){ //Condição para caso letra seja maiúscula
                ch = (char)(((int)texto.charAt(n) + chave - 65) % 26 + 65); 
                textoCifrado.append(ch);
                encriptar(texto, textoCifrado, n+1);
            } 
            else if(texto.charAt(n) == ' '){ //condição para quando um espaço seja encontrado
                ch = ' ';
                textoCifrado.append(ch);
                encriptar(texto, textoCifrado, n+1);
            }
            else {
                ch = (char)(((int)texto.charAt(n) + chave - 97) % 26 + 97); //condição para letra minúscula. 
                textoCifrado.append(ch);
                encriptar(texto, textoCifrado, n+1);
            }
    }
   
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String fraseNormal = new String();
        StringBuilder fraseCifrada = new StringBuilder();
        
        fraseNormal = sc.nextLine();
        
        while(fraseNormal.equals("FIM") != true){ //Loop é interrompido quando a string FIM é identificada.
            encriptar(fraseNormal,fraseCifrada,0);
            System.out.printf(fraseCifrada + "\n");
            fraseCifrada.delete(0, fraseCifrada.length()); //Limpa a string.
            fraseNormal = sc.nextLine();
        }
        sc.close();
    }
}