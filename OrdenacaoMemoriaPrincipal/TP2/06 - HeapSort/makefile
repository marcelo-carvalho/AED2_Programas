all: exec
 
exec: main.o geracao.o heapsort.o
	g++ -o exec main.o geracao.o heapsort.o -lpsapi 
 
main.o: main.c 
	g++ -o main.o main.c -c -W -Wall -pedantic -lpsapi 

geracao.o: geracao.c 
	g++ -o geracao.o geracao.c -c -W -Wall -pedantic

heapsort.o: heapsort.c 
	g++ -o heapsort.o heapsort.c -c -W -Wall -pedantic

clean:
	rm -rf *.o *~ exec

limpa: 
	rm -rf *.o  