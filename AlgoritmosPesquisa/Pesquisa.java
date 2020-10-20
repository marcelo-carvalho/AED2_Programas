import java.util.Random;

class Main {
    public static int[] gerarVetorAleatorio(int n){
        int[] v = new int [n];
        Random random = new Random();

        for(int i=0; i<n; i++){
            v[i] = i+1;
        }

        for(int i=0; i <n; i++){
            int pos = random.nextInt(n);
            int tmp = v[pos];
            v[pos] = v[i];
            v[i] = tmp;
        }

        return v;
    }

    public static int[] gerarVetorOrdemCrescente(int n){
        int[] v = new int[n];

        for(int i=0; i<n; i++){
            v[i] = i+1;
        }

        return v;
    }

    public static Boolean pesquisaSequencial(int[] v, int chave){
        int cont_instrucao = 0;
        for(int i=0; i<v.length; i++){
            if(v[i] == chave){
                System.out.println("Instricoes: " + cont_instrucao);
                return true;
            }
            cont_instrucao++;
        }
        System.out.println("Instricoes: " + cont_instrucao);
        return false;
    }

    
    public static boolean pesquisaBinaria(int[] v, int chave){
        int ini = 0;
        int fim = v.length - 1;
        int meio;
        int cont_instrucao = 0; 

        while(ini <= fim) {
            meio = (ini + fim) / 2;
            if(chave < v[meio])
                fim = meio - 1; // ajusta posição final 
            else if (chave > v[meio])
                ini = meio + 1; //ajusta posição inícial
            else{
                System.out.println("Instricoes: " + cont_instrucao);
                return true; // elemento encontrado
            }
            
            cont_instrucao++;
        }
        System.out.println("Instricoes: " + cont_instrucao);
        return false; //Não encontrou
    }

    public static boolean pesquisaBinariaRecusriva(int[] v, int chave, int ini, int fim){
        int meio = (ini + fim) / 2;

        if(chave < v[meio]){
            fim = meio - 1;
            return pesquisaBinariaRecusriva(v, chave, ini, fim);
        }
        else if(chave > v[meio]){
            ini = meio + 1;
            return pesquisaBinariaRecusriva(v, chave, ini, fim);
        }
        else if(ini > fim){
            return false;
        }
        else{
            return true; // elemento encontrado
        }
    }

    public static void printVetor(int[] v){
        System.out.print("[");

        for(int i=0; i<v.length; i++){
            System.out.print(v[i] + " ");
        }

        System.out.print("]");
    }

    public static void main(String[] args){

        int[] v = gerarVetorOrdemCrescente(10);
        //v = gerarVetorAleatorio(10);
        printVetor(v);
        System.out.println();

        if(pesquisaBinariaRecusriva(v,10, 0, 9))
            System.out.println("Encontrado");
        else
            System.out.println("Não Encontrado");

    }
}