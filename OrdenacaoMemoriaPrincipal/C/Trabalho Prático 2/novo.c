#include <stdio.h>
#include <time.h>
#include <sys\timeb.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>
#include <stdlib.h>

double get_memory_used_MB();
void swap(int *i, int *j);
void crescente(int *array, int n);
void crescente(int *array, int n);
void decrescente(int *array, int n);
void aleatorio(int *array, int n);
void bolha(int *array, int n);
void insercao(int *array, int n);
void shellsort(int *array, int n);
void insercaoPorCor(int *array, int n, int cor, int h, int*comparacao, int*trocas);
void intercalar(int* array, int esq, int meio, int dir,int *comparacao, int *trocas);
void mergesortRec(int *array, int esq, int dir, int *comparacao, int *trocas);
void mergesort(int *array, int n);
void quicksort(int *array, int n);
void quicksortRec(int *array, int esq, int dir, int *comparacao, int *trocas);
void heapsort(int *array, int n);
void reconstroi(int *array, int tamHeap, int *comparacao, int *trocas);
int getMaiorFilho(int *array, int i, int tamHeap,int*comparacao);
void constroi(int *array, int tamHeap, int* comparacao, int*trocas);
void countingsort(int *array, int n);
int getMaior(int *array, int n,int *comparacao);


int main(){
    int sorting;
    int caso;
    int tamanho;
    int *vetor;
    struct timeb inicio, fim;//clock_t inicio, fim; //váriaveis de tempo
    double memory_used; //utilizacao da memoria

    scanf("%d %d %d", &sorting, &caso, &tamanho);

    while(sorting != 555 ){
        
        vetor = (int*) malloc(tamanho * sizeof(int));

        printf("%d", sorting);
        printf("\t%d", caso);
        printf("\t%d", tamanho);

        //Criao vetor de acordo com o caso a ser analisado.
        switch(caso){
            case 0:
                crescente(vetor,tamanho);
                break;
            case 1:
                aleatorio(vetor,tamanho);
                break;
            case 2:
                decrescente(vetor,tamanho);
                break;
        }

        ftime(&inicio);//inicio = clock(); //Inicia o timer

        switch(sorting){
            case 0:
                bolha(vetor,tamanho);
                break;
            case 1:
                insercao(vetor,tamanho);
                break;
            case 2:
                printf("Chegou no case 2\n");
                shellsort(vetor,tamanho);
                printf("Saiu do shellsort\n");
                break;
            case 3:
                mergesort(vetor,tamanho);
                break;
            case 4:
                quicksort(vetor,tamanho);
                break;
            case 5:
                heapsort(vetor,tamanho);
                break;
            case 6:
                countingsort(vetor,tamanho);
                break;
        }

        ftime(&fim);//fim = clock(); // Para o timer.

        free(vetor); //libera a memoria do vetor. 

        memory_used = get_memory_used_MB(); //Coleta a quantidade de memoria usada.
        int tempo_decorrido = (int) (1000.0 * (fim.time - inicio.time) + (fim.millitm - inicio.millitm)) ; //(float) (fim - inicio) * 1000 /CLOCKS_PER_SEC ; //Tempo decorrido
        
        printf("\t%0.2f", memory_used);
        printf("\t%u", tempo_decorrido);
        printf("\n");

        scanf("%d %d %d", &sorting, &caso, &tamanho);
    }

    return 0;
}

double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess( ), &info, sizeof(info) );
    return (double)info.PeakWorkingSetSize/ (1024*1024);
}

//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM CRESCENTE
void crescente(int *array, int n) {
   for (int i = 0; i < n; i++) {
      array[i] = i;
   }
}

//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM ALEATORIA
void aleatorio(int *array, int n) {
   crescente(array, n);
   srand(time(NULL));
   for (int i = 0; i < n; i++) {
      swap(&array[i], &array[rand() % n]);
   }
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM DECRESCENTE
void decrescente(int *array, int n) {
   for (int i = 0; i < n; i++) {
      array[i] = n - 1 - i;
   }
}
//=============================================================================
// PROCEDIMENTO PARA TROCAR DOIS ELEMENTOS DO VETOR
void swap(int *i, int *j) {
   int temp = *i;
   *i = *j;
   *j = temp;
}

//=============================================================================
void bolha(int *array, int n){
    int i, j;
    int comparacao = 0; 
    int trocas = 0;
    
    for (i = (n - 1); i > 0; i--) {
      for (j = 0; j < i; j++) {
         comparacao++;
         if (array[j] > array[j + 1]) {
            swap(&array[j], &array[j + 1]);
            trocas++;
         }
      }
   }
   printf("\t%d", comparacao);
   printf("\t%d", trocas);
}
//=============================================================================

//=============================================================================
void insercao(int *array, int n){
   int comparacao = 0; 
   int trocas = 0;
   for (int i = 1; i < n; i++) {
      int tmp = array[i];
      int j = i - 1;

      
      while ((j >= 0) && (array[j] > tmp)) {
         comparacao++;
         array[j + 1] = array[j];
         j--;
         trocas++;
      }
      array[j+1] = tmp;
   }
   printf("\t%d", comparacao);
   printf("\t%d", trocas);
}
//=============================================================================

//=============================================================================
void insercaoPorCor(int *array, int n, int cor, int h, int*comparacao, int*trocas){
    for (int i = (h + cor); i < n; i+=h) {
        int tmp = array[i];
        int j = i - h;
        *comparacao++;
        while ((j >= 0) && (array[j] > tmp)) {
            printf("chegou no while\n");
            array[j + h] = array[j];
            j-=h;
            *trocas++;
        }
        array[j + h] = tmp;
    }
}
//=============================================================================
void shellsort(int *array, int n) {
    int h = 1;
    int *comparacao; 
    int *trocas;

    *comparacao = 0;
    *trocas = 0;

    do { h = (h * 3) + 1; } while (h < n);

    do {
        h /= 3;
        for(int cor = 0; cor < h; cor++){
            printf("Chegou no for do shellsort");
            insercaoPorCor(array, n, cor, h,comparacao,trocas);
        }
    } while (h != 1);

    printf("\t%d", *comparacao);
    printf("\t%d", *trocas);
}
//=============================================================================

//=============================================================================
void mergesort(int *array, int n) {
   int *comparacao; 
   int *trocas;

   *comparacao = 0;
   *trocas = 0;
   mergesortRec(array, 0, n-1,comparacao,trocas);

   printf("\t%d", *comparacao);
   printf("\t%d", *trocas);
}
//=============================================================================
void mergesortRec(int *array, int esq, int dir, int *comparacao, int *trocas){
   if (esq < dir){
      int meio = (esq + dir) / 2;
      mergesortRec(array, esq, meio,comparacao,trocas);
      mergesortRec(array, meio + 1, dir,comparacao,trocas);
      intercalar(array, esq, meio, dir,comparacao,trocas);
   }
}
//=============================================================================
void intercalar(int* array, int esq, int meio, int dir,int *comparacao, int *trocas){
   int n1, n2, i, j, k;

   //Definir tamanho dos dois subarrays
   n1 = meio-esq+1;
   n2 = dir - meio;

   int* a1 = (int*) malloc((n1+1) * sizeof(int)); 
   int* a2 = (int*) malloc((n2+1) * sizeof(int));

   //Inicializar primeiro subarray
   for(i = 0; i < n1; i++){
      a1[i] = array[esq+i];
   }

   //Inicializar segundo subarray
   for(j = 0; j < n2; j++){
      a2[j] = array[meio+j+1];
   }

   //Sentinela no final dos dois arrays
   a1[i] = a2[j] = 0x7FFFFFFF;

   //Intercalacao propriamente dita
   for(i = j = 0, k = esq; k <= dir; k++){
      *comparacao++;
      if(a1[i] <= a2[j]){
         array[k] = a1[i++];
         trocas++;
      }
      else{
          array[k] = a2[i++];
          trocas++;
      }
      //array[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
   }
}
//=============================================================================

//=============================================================================
void quicksortRec(int *array, int esq, int dir, int *comparacao, int *trocas) {
    int i = esq, j = dir;
    int pivo = array[(dir+esq)/2];
     
    while (i <= j) {
        while (array[i] < pivo) {*comparacao++; i++;}
        while (array[j] > pivo) {*comparacao++; j--;}
        if (i <= j) {
            swap(array + i, array + j);
            *trocas++;
            i++;
            j--;
        }
    }
    if (esq < j)  quicksortRec(array, esq, j,comparacao,trocas);
    if (i < dir)  quicksortRec(array, i, dir,comparacao,trocas);
}
//=============================================================================
void quicksort(int *array, int n) {
    int *comparacao;
    int *trocas;
    *comparacao = 0;
    *trocas = 0;

    quicksortRec(array, 0, n-1,comparacao,trocas);

    printf("\t%d", *comparacao);
    printf("\t%d", *trocas);
}
//=============================================================================

//=============================================================================
void constroi(int *array, int tamHeap, int* comparacao, int*trocas){
    for(int i = tamHeap; i > 1 && array[i] > array[i/2]; i /= 2){
        comparacao++;
        swap(array + i, array + i/2);
        trocas++;
    }
}
//=============================================================================
int getMaiorFilho(int *array, int i, int tamHeap,int*comparacao){
    int filho;
    *comparacao++;
    if (2*i == tamHeap || array[2*i] > array[2*i+1]){
        filho = 2*i;
    } else {
        filho = 2*i + 1;
    }
    return filho;
}
//=============================================================================
void reconstroi(int *array, int tamHeap, int *comparacao, int *trocas){
    int i = 1;
    while(i <= (tamHeap/2)){
        int filho = getMaiorFilho(array, i, tamHeap,comparacao);
        *comparacao++;
        if(array[i] < array[filho]){
            swap(array + i, array + filho);
            *trocas++;
            i = filho;
        }else{
            i = tamHeap;
        }
    }
}
//=============================================================================
void heapsort(int *array, int n) {
    int *comparacao;
    int *trocas;
    *comparacao = 0;
    *trocas = 0;
    
    //Alterar o vetor ignorando a posicao zero
    int *arrayTmp = (int*) malloc(n+1 * sizeof(int));
    
    for(int i = 0; i < n; i++){
        arrayTmp[i+1] = array[i];
    }

    //Contrucao do heap
    for(int tamHeap = 2; tamHeap <= n; tamHeap++){
        constroi(arrayTmp, tamHeap,comparacao,trocas);
    }

    //Ordenacao propriamente dita
    int tamHeap = n;
    while(tamHeap > 1){
        swap(arrayTmp + 1, arrayTmp + tamHeap--);
        *trocas++;
        reconstroi(arrayTmp, tamHeap,comparacao,trocas);
    }

    //Alterar o vetor para voltar a posicao zero
    for(int i = 0; i < n; i++){
        array[i] = arrayTmp[i+1];
        *trocas++;
    }

    printf("\t%d", *comparacao);
    printf("\t%d", *trocas);
}
//=============================================================================

//=============================================================================
int getMaior(int *array, int n,int *comparacao) {
    int maior = array[0];

    for (int i = 0; i < n; i++) {
        *comparacao++;
        if(maior < array[i]){
            maior = array[i];
        }
    }
    return maior;
}
//=============================================================================
void countingsort(int *array, int n) {
    int *comparacao;
    //Array para contar o numero de ocorrencias de cada elemento
    int tamCount = getMaior(array, n,comparacao) + 1;
    int *count = (int*) malloc(tamCount * sizeof(int));
    int *ordenado = (int*) malloc(n * sizeof(int));

    //Inicializar cada posicao do array de contagem 
    for (int i = 0; i < tamCount; count[i] = 0, i++);

    //Agora, o count[i] contem o numero de elemento iguais a i
    for (int i = 0; i < n; count[array[i]]++, i++);

    //Agora, o count[i] contem o numero de elemento menores ou iguais a i
    for(int i = 1; i < tamCount; count[i] += count[i-1], i++);

    //Ordenando
    for(int i = n-1; i >= 0; ordenado[count[array[i]]-1] = array[i], count[array[i]]--, i--);

    //Copiando para o array original
    for(int i = 0; i < n; array[i] = ordenado[i], i++);

    printf("\t%d", *comparacao);
    printf("\t%d", n);
}
//=============================================================================