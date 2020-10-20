all: exec
 
exec: main.o geracao.o bolha.o countingsort.o heapsort.o insercao.o mergesort.o quicksort.o selecao.o shellsort.o
	g++ -o exec main.o geracao.o bolha.o countingsort.o heapsort.o insercao.o mergesort.o quicksort.o selecao.o shellsort.o -lpsapi 
 
main.o: main.c 
	g++ -o main.o main.c -c -W -Wall -pedantic -lpsapi 
 
bolha.o: bolha.c 
	g++ -o bolha.o bolha.c -c -W -Wall -pedantic

countingsort.o: countingsort.c 
	g++ -o countingsort.o countingsort.c -c -W -Wall -pedantic

geracao.o: geracao.c 
	g++ -o geracao.o geracao.c -c -W -Wall -pedantic

heapsort.o: heapsort.c 
	g++ -o heapsort.o heapsort.c -c -W -Wall -pedantic

insercao.o: insercao.c 
	g++ -o insercao.o insercao.c -c -W -Wall -pedantic

mergesort.o: mergesort.c 
	g++ -o mergesort.o mergesort.c -c -W -Wall -pedantic

quicksort.o: quicksort.c 
	g++ -o quicksort.o quicksort.c -c -W -Wall -pedantic

selecao.o: selecao.c 
	g++ -o selecao.o selecao.c -c -W -Wall -pedantic

shellsort.o: shellsort.c 
	g++ -o shellsort.o shellsort.c -c -W -Wall -pedantic

clean:
	rm -rf *.o *~ exec

limpa: 
	rm -rf *.o  