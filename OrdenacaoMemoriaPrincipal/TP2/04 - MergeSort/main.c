#include <stdio.h>
#include <time.h>
#include <sys\timeb.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>
#include <stdlib.h>

#include "mergesort.h"

double get_memory_used_MB();

int main(){
    int sorting;
    int caso;
    int tamanho;
    int *vetor;
    struct timeb inicio, fim;//clock_t inicio, fim; //váriaveis de tempo
    double memory_used; //utilizacao da memoria

    scanf("%d %d %d", &sorting, &caso, &tamanho);


    while(sorting != 0 ){
        
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

        mergesort(vetor,tamanho);

        
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
