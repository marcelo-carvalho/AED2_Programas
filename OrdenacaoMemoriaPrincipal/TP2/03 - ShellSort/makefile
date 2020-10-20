all: exec
 
exec: main.o geracao.o  shellsort.o
	g++ -o exec main.o geracao.o shellsort.o -lpsapi 
 
main.o: main.c 
	g++ -o main.o main.c -c -W -Wall -pedantic -lpsapi 
 
geracao.o: geracao.c 
	g++ -o geracao.o geracao.c -c -W -Wall -pedantic

shellsort.o: shellsort.c 
	g++ -o shellsort.o shellsort.c -c -W -Wall -pedantic

clean:
	rm -rf *.o *~ exec

limpa: 
	rm -rf *.o  