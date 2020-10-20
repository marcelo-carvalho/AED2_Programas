all: exec
 
exec: main.o geracao.o mergesort.o
	g++ -o exec main.o geracao.o mergesort.o -lpsapi 
 
main.o: main.c 
	g++ -o main.o main.c -c -W -Wall -pedantic -lpsapi 

geracao.o: geracao.c 
	g++ -o geracao.o geracao.c -c -W -Wall -pedantic

mergesort.o: mergesort.c 
	g++ -o mergesort.o mergesort.c -c -W -Wall -pedantic

clean:
	rm -rf *.o *~ exec

limpa: 
	rm -rf *.o  