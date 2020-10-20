#include <stdio.h>
#include <stdlib.h>

int mais_proximo(int *v, int n, int x){
    int esq = 0, dir = n-1;

    //Busca binaria simples
    while(esq <= dir){
      int meio = (esq + dir) /2;

      if(v[meio] == x){
          return x;
      }
      if(x > v[meio]){
          esq = meio+1;
      }
      else{
          dir = meio-1;
      }
    }

    //Condição para retorno do melhor valor 
    if(v[esq] - x < x - v[dir]){ 
        return v[esq];
    } 
    else{
        return v[dir];
    } 
}

int main()
{
    int v[] = {3, 7, 10, 14, 16};
    int n = sizeof(v)/ sizeof(int);
    int x = 5;
    int retorno = mais_proximo(v, n, x);
    printf("%d", retorno);
    return 0;
}