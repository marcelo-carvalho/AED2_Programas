import java.util.Scanner;

public class CifraCesar{
   
    public static String encriptar(String texto) {
        StringBuilder textoCifrado = new StringBuilder();
        int n = texto.length(); //Identifica o tamanho da string
        int chave = 3; // determina o valor do deslocamento das letras
        char ch;
            
        for (int i=0; i < n; i++){
            
            if (Character.isUpperCase(texto.charAt(i))){ //Condição para caso letra seja maiúscula
                ch = (char)(((int)texto.charAt(i) + chave - 65) % 26 + 65); 
                textoCifrado.append(ch);
            } 
            else if(texto.charAt(i) == ' '){ //condição para quando um espaço seja encontrado
                ch = ' ';
                textoCifrado.append(ch);
            }
            else {
                ch = (char)(((int)texto.charAt(i) + chave - 97) % 26 + 97); //condição para letra minúscula. 
                textoCifrado.append(ch);
            }
        }
        return textoCifrado.toString();
    }
   
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String fraseNormal = new String();
        String fraseCifrada = new String();
        
        fraseNormal = sc.nextLine();
        
        while(fraseNormal.equals("FIM") != true){ //Loop é interrompido quando a string FIM é identificada.
            fraseCifrada = encriptar(fraseNormal);
            System.out.printf(fraseCifrada + "\n");
            fraseNormal = sc.nextLine();
        }

        sc.close();
    }
}