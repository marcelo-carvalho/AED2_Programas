#include <stdio.h>

void insercao(int *array, int n);

int main(){
    int par[105];
    int impar[105];
    int n, entrada;
    int contador_par;
    int contador_impar = 0;

    scanf("%d",&n);
    if(n > 0 && n < 105){
        for(int i=0; i < n; i++){
            scanf("%d", &entrada);
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
            printf("%d\n",par[i]);
        }
            
        for(int i = contador_impar -1 ; i >= 0; i-- ) {
            printf("%d\n",impar[i]);
        }
    }
    return 0;
}

void insercao(int *array, int n){
    for (int i = 1; i < n; i++) {
      int tmp = array[i];
      int j = i - 1;

      while ((j >= 0) && (array[j] > tmp)) {
         array[j + 1] = array[j];
         j--;
      }
      array[j+1] = tmp;
   }
}
